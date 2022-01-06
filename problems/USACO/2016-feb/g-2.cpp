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

ll dp[8][105];

int main() {
//    setIO("cbarn2");
    int n, K;
    cin>>n>>K;
    vi cows;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cows.pb(a);
    }
    ll result=0x7fffffff;
    for (int i=0;i<n;i++){
        memset(dp, 0x7f, sizeof dp);
        dp[0][n]=0;
        for (int k=1;k<=K;k++){
            for (int j=0;j<n;j++){
                ll val=0;
                for (int a=j+1;a<=n;a++){
                    val+=cows[a-1]*(a-j-1);
                    dp[k][j]=min(dp[k][j], val+dp[k-1][a]);
                }
            }
        }
        result=min(result, dp[K][0]);
        rotate(cows.begin(), cows.begin()+1, cows.end());
    }
    cout<<result<<endl;
    return 0;
}