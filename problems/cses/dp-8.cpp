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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a, x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

ll dp[100005][105], a[100005], mod=1e9+7;

int main(){
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<n;++i){
		cin>>a[i];
		a[i]--;
	}
	for (int i=0;i<n;++i){
		if (i) {
			for (int j=0;j<m;++j){
				dp[i][j]=dp[i-1][j];
				if (j) dp[i][j]+=dp[i-1][j-1];
				if (j+1<m) dp[i][j]+=dp[i-1][j+1];
				dp[i][j]%=mod;
			}
		} else {
			for (int j=0;j<m;++j){
				dp[i][j]=1;
			}
		}
		if (~a[i]) {
			for (int j=0;j<m;++j){
				if (j^a[i])
					dp[i][j]=0;
			}
		}
	}
	ll ans=0;
	for (int i=0;i<m;++i){
		ans+=dp[n-1][i];
	}
	cout<<ans%mod<<endl;
	return 0;
}

