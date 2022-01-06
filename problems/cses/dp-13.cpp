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

int dp[62630];

int main() {
//    setIO("");
	int n, mod=1e9+7;
	cin>>n;
	if ((1+n)*n%4!=0){
		cout<<0<<endl;
		return 0;
	}
	int half_sum=(1+n)*n/4;
	dp[0]=1;
	for (int i=1;i<n;i++){
		for (int j=half_sum;j>=i;j--){
			dp[j]=(dp[j]+dp[j-i])%mod;
		}
	}
	cout<<dp[half_sum]<<endl;
	return 0;
}

