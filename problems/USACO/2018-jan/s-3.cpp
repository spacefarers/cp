#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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

int vids[5001][5001], n, q;
bool visited[5001][5001];
vi paths[5001];

void dfs(int x, int y, int rel){
    if (visited[x][y])return;
    visited[x][y]=true;
    if (vids[x][y]==0) {
        vids[x][y] = rel;
        vids[y][x] = rel;
    }
    trav(i, paths[y]){
        dfs(x, i, min(vids[y][i], rel));
    }
}

int main() {
    setIO("mootube");
    cin>>n>>q;
    for (int i=0;i<n-1;i++){
        int a, b, c;
        cin>>a>>b>>c;
        vids[a][b]=c;
        vids[b][a]=c;
        paths[a].pb(b);
        paths[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        dfs(i, i, 0x7fffffff);
    }
    for (int i=0;i<q;i++){
        int c=0;
        int k, s;
        cin>>k>>s;
        for (int j=1;j<=n;j++){
            if (vids[s][j]>=k&&j!=s) c++;
        }
        cout<<c<<endl;
    }
    return 0;
}