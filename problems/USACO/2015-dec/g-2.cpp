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

bool dp[1000005];

int main() {
//    setIO("feast");
    int n, a, b;
    cin>>n>>a>>b;
    dp[0]=true;
    for (int i=1;i<n;i++){
        if (i-a>=0&&dp[i-a]) dp[i]=true;
        if (i-b>=0&&dp[i-b]) dp[i]=true;
    }
    for (int i=n;i>=0;i--){
        if (dp[i-(a)/2]||dp[i]||dp[i-(b)/2]||dp[i-(a+b)/2]) {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}