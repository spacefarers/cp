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

int dp[1000005];

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main() {
//    setIO("");
    int n;
    cin>>n;
    memset(dp, 0x7f, sizeof dp);
    dp[n]=0;
    for (int i=n;i>=0;i--){
        if (dp[i]>1000000) continue;
        int a=i;
        while (a>0){
            int c=a%10;
            if (i-c<0) continue;
            dp[i-c]=min(dp[i-c], dp[i]+1);
            a/=10;
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}
