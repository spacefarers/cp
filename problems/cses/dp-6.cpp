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

string grid[1005];
ll dp[1005][1005], mod=1e9+7;

int main() {
//    setIO("");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        grid[i]=a;
    }
    if (grid[0][0]!='*')
        dp[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==0&&j==0) continue;
            if (i>0) dp[i][j]+=dp[i-1][j];
            if (j>0) dp[i][j]+=dp[i][j-1];
            if (grid[i][j]=='*') dp[i][j]=0;
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}

