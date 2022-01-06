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

int dp[5000][5000];

int main() {
//    setIO("");
	string a, b;
	cin>>a>>b;
	memset(dp, 0x7f, sizeof dp);
	dp[1][1]=0;
	for (int i=1;i<=a.size()+1;++i){
		for (int j=1;j<=b.size()+1;++j){
			dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
			dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
			dp[i][j]=min(dp[i][j], dp[i-1][j-1]+(a[i-2]!=b[j-2]));
		}
	}
	cout<<dp[a.size()+1][b.size()+1]<<endl;
	return 0;
}

