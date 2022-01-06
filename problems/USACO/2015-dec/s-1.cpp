#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

int n, m, ans=0;
bool changed=true;
map<pi, vpi> paths;
map<pi, bool> lit, visited;

void dfs(pi a){
    if (!lit[a]||visited[a]) return;
    visited[a]=true;
    ans++;
    trav(i, paths[a]){
        if (!lit[i]){
            changed=true;
            lit[i]=true;
        }
    }
    dfs({a.f-1, a.s});
    dfs({a.f+1, a.s});
    dfs({a.f, a.s-1});
    dfs({a.f, a.s+1});
}

int main() {
    setIO("lightson");
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        paths[{x, y}].pb({a, b});
    }
    lit[{1, 1}]=true;
    while (changed){
        changed=false;
        visited.clear();
        ans=0;
        dfs({1, 1});
    }
    ans=0;
    trav(i, lit){
        if (i.s) ans++;
    }
    cout<<ans<<endl;
    return 0;
}