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

bool can[205][205];

int main() {
    setIO("pails");
    int x, y, k, m;
    cin>>x>>y>>k>>m;
    can[0][0]=true;
    for (int i=0;i<k;i++){
        vpi moves;
        for (int j=0;j<203;j++){
            for (int t=0;t<203;t++){
                if (!can[j][t]) continue;
                moves.pb({0, t});
                moves.pb({j, 0});
                moves.pb({x, t});
                moves.pb({j, y});
                int p=min(y-t, j);
                moves.pb({j-p, t+p});
                p=min(x-j, t);
                moves.pb({j+p, t-p});
            }
        }
        trav(p, moves){
            can[p.f][p.s]=true;
        }
    }
    int ans=m;
    for (int i=0;i<205;i++){
        for (int j=0;j<205;j++){
            if (can[i][j]){
                ans=min(ans, abs(m-i-j));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}