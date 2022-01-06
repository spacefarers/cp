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

vi cows[205];
int ans[205];
int n, m;

int main() {
    setIO("revegetate");
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        cows[a].pb(b);
        cows[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        int c=1;
        while (true){
            bool ok=true;
            trav(u, cows[i]){
                if (ans[u]==c) {
                    c++;
                    ok=false;
                    break;
                }
            }
            if (ok) break;
        }
        ans[i]=c;
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i];
    }
    return 0;
}