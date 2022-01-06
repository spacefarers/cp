#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <unordered_set>

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

vi paths[3005];
bool visited[3005];

unordered_set<int> avails;

void dfs(int x){
    if (visited[x]) return;
    visited[x]=true;
    trav(i, paths[x]){
        if (avails.find(i)!=avails.end())
            dfs(i);
    }
}

int main() {
    setIO("closing");
    int n, m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        avails.insert(a);
        avails.insert(b);
        paths[a].pb(b);
        paths[b].pb(a);
    }
    for (int i=0;i<n;i++){
        memset(visited, false, sizeof visited);
        dfs(*avails.begin());
        bool ok=true;
        trav (j, avails){
            if (!visited[j]) ok=false;
        }
        if (ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        int a;
        cin>>a;
        avails.erase(a);
    }
    return 0;
}