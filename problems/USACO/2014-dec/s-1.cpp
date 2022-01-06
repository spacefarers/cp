#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

vi paths[40005];
int dist_b[40005], dist_e[40005], dist_t[40005];

int main() {
    setIO("piggyback");
    int B, E, P, N, M;
    cin>>B>>E>>P>>N>>M;
    for (int i=0;i<M;i++) {
        int a, b;
        cin>>a>>b;
        paths[a].pb(b);
        paths[b].pb(a);
    }
    priority_queue<pi, vpi, greater<pi>> q;
    memset(dist_t, 0x7f, sizeof dist_t);
    q.push({0, N});
    dist_t[N]=0;
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        trav(i, paths[u.s]){
            if (dist_t[i]>dist_t[u.s]+1){
                dist_t[i]=dist_t[u.s]+1;
                q.push({dist_t[i], i});
            }
        }
    }
    memset(dist_b, 0x7f, sizeof dist_b);
    q.push({0, 1});
    dist_b[1]=0;
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        trav(i, paths[u.s]){
            if (dist_b[i]>dist_b[u.s]+1){
                dist_b[i]=dist_b[u.s]+1;
                q.push({dist_b[i], i});
            }
        }
    }
    memset(dist_e, 0x7f, sizeof dist_e);
    q.push({0, 2});
    dist_e[2]=0;
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        trav(i, paths[u.s]){
            if (dist_e[i]>dist_e[u.s]+1){
                dist_e[i]=dist_e[u.s]+1;
                q.push({dist_e[i], i});
            }
        }
    }
    int best_ans=0x7fffffff;
    for (int i=1;i<=N;i++){
        best_ans=min(best_ans, dist_b[i]*B+dist_e[i]*E+dist_t[i]*P);
    }
    cout<<best_ans<<endl;
    return 0;
}

