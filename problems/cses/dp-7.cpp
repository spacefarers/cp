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

int dp[100005], p[1005], v[1005];

int main() {
//    setIO("");
    int n, x;
    cin>>n>>x;
    for (int i=0;i<n;i++) cin>>p[i];
    for (int i=0;i<n;i++) cin>>v[i];
    for (int i=0;i<n;i++){
        for (int j=x;j>=p[i];j--){
            dp[j]=max(dp[j], dp[j-p[i]]+v[i]);
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}

