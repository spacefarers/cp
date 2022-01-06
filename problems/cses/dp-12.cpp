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

ll dp[5000][5000];

int main() {
//    setIO("");
	int n;
	cin>>n;
	vi nums(n);
	ll sum_all=0;
	for (int i=0;i<n;++i){
		cin>>nums[i];
		dp[i][i]=nums[i];
		sum_all+=nums[i];
	}
	for (int i=1;i<n;i++){
		for (int j=0;j<n-i;++j){
			dp[j][j+i]=max(nums[j]-dp[j+1][j+i], nums[j+i]-dp[j][j+i-1]);
		}
	}
	cout<<((sum_all+dp[0][n-1])>>1)<<endl;
	return 0;
}