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

int dp[1000005];

int main() {
//    setIO("");
    int n, x;
    cin>>n>>x;
    vi coins(n);
    for (int i=0;i<n;i++){
        cin>>coins[i];
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0]=0;
    for (int i=1;i<=x;i++){
        trav(j, coins){
            if (i-j<0) continue;
            dp[i]=min(dp[i-j]+1, dp[i]);
        }
    }
    if (dp[x]>1000000) dp[x]=-1;
    cout<<dp[x]<<endl;
    return 0;
}

