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

bool dp[100005];

int main() {
//    setIO("");
	int n;
	cin>>n;
	vi coins(n);
	int mmax=0;
	for (int i=0;i<n;++i){
		cin>>coins[i];
		mmax+=coins[i];
	}
	dp[0]=true;
	trav(i, coins){
		for (int j=mmax;j>=i;j--){
			dp[j]=dp[j]||dp[j-i];
		}
	}
	int ans=0;
	vi f_ans;
	for (int i=1;i<=mmax;i++){
		if (dp[i]) {
			ans++;
			f_ans.pb(i);
		}
	}
	cout<<ans<<endl;
	trav(i, f_ans){
		cout<<i<<" ";
	}
	return 0;
}

