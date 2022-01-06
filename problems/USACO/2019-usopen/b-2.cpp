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

vi factories[105];
bool visited[105];

void dfs(int x){
    if (visited[x]) return;
    visited[x]=true;
    trav(i, factories[x]){
        dfs(i);
    }
}

int main() {
    setIO("factory");
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        factories[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        bool ok=true;
        for (int j=1;j<=n;j++){
            if (!visited[j]) {
                ok=false;
                break;
            }
        }
        if (ok){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}