#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
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

int n, m, k, dist[100005], dist1[100005];
vpi paths[100005];
map<int, int> mp;

int main() {
    setIO("dining");
    cin>>n>>m>>k;
    for (int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        paths[a].emplace_back(b, c);
        paths[b].emplace_back(a, c);
    }
    for (int i=0;i<k;i++){
        int a, b;
        cin>>a>>b;
        mp[a]=max(mp[a], b);
    }
//    djikstra
    priority_queue<pi, vpi, greater<pi>> q;
    memset(dist, 0x7f, sizeof(dist));
    dist[n]=0;
    q.push(make_pair(0, n));
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        trav (e, paths[u.second]){
            if (dist[e.first]>e.second+dist[u.second]){
                dist[e.first]=e.second+dist[u.second];
                q.push(make_pair(dist[e.first], e.first));
            }
        }
    }
    trav(u, mp){
        paths[n+1].emplace_back(u.first, dist[u.first]-u.second);
    }
    memset(dist1, 0x7f, sizeof(dist1));
    dist1[n+1]=0;
    q.push(make_pair(0, n+1));
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        trav (e, paths[u.second]){
            if (dist1[e.first]>e.second+dist1[u.second]){
                dist1[e.first]=e.second+dist1[u.second];
                q.push(make_pair(dist1[e.first], e.first));
            }
        }
    }
    for (int i=1;i<n;i++){
        if (dist1[i]<=dist[i]) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}