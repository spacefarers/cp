/*
ID: michael419
LANG: C++11
TASK: numtri
*/

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

int dp[1005][1005];

int main() {
    setIO("numtri");
    int R;
    cin>>R;
    for (int i=1;i<=R;i++){
        for (int j=1;j<=i;j++){
            cin>>dp[i][j];
            dp[i][j]+=max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    int ans=0;
    for (int i=1;i<=R;i++){
        ans=max(ans, dp[R][i]);
    }
    cout<<ans<<endl;
    return 0;
}

