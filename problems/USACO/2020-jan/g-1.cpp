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

ll n, m, c, rewards[1005], dp[2][1005];
vpi paths;

int main() {
//    setIO("time");
    cin>>n>>m>>c;
    for (int i=1;i<=n;i++){
        cin>>rewards[i];
    }
    for (int i=0;i<m;i++){
        ll a, b;
        cin>>a>>b;
        paths.emplace_back(a, b);
    }
    ll ans=0;
    memset(dp, -1, sizeof dp);
    dp[0][1]=0;
    for (int i=1;i<=1000;i++){
        int p=i%2;
        memset(dp[p], -1, sizeof dp[p]);
        trav(j, paths){
            if (dp[1-p][j.f]<0) continue;
            dp[p][j.s]=max(dp[p][j.s], dp[1-p][j.f]+rewards[j.s]);
        }
        ans=max(ans, dp[p][1]-c*i*i);
    }
    cout<<ans<<endl;
    return 0;
}