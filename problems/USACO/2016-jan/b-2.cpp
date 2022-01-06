#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
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

vpi bales;
bool visited[105];

//void explode(pi x, int t){
//    if (visited[x.s]) return;
//    visited[x.s]=true;
//    trav(i, bales){
//        if (abs(i.f-x.f)<=t)
//            explode(i, t+1);
//    }
//}

int main() {
    setIO("angry");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        bales.pb({a, i});
    }
    sort(all(bales));
    int ans=0;
    trav(i, bales){
        memset(visited, false, sizeof visited);
        int t=1;
        queue<pi> q, new_q;
        new_q.push(i);
        visited[i.s]=true;
        while (!new_q.empty()){
            swap(q, new_q);
            queue<pi> empty;
            swap(new_q, empty);
            while (!q.empty()) {
                auto u=q.front();
                q.pop();
                trav(j, bales) {
                    if (!visited[j.s]&&abs(j.f - u.f) <= t) {
                        visited[j.s]=true;
                        new_q.push(j);
                    }
                }
            }
            t++;
        }
        int c_ans=0;
        for (int j=0;j<n;j++){
            if (visited[j]) c_ans++;
        }
        ans=max(ans, c_ans);
    }
    cout<<ans<<endl;
    return 0;
}