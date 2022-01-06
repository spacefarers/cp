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

int dp[505][505];

int main() {
//    setIO("");
	int a, b;
	cin>>a>>b;
	memset(dp, 0x7f, sizeof dp);
	for (int i=1;i<=max(a, b);i++){
		dp[i][i]=0;
	}
	for (int i=1;i<=a;++i){
		for (int j=1;j<=b;j++){
			for (int k=1;k<i;k++)
				dp[i][j]=min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
			for (int k=1;k<j;k++)
				dp[i][j]=min(dp[i][j], dp[i][j-k]+dp[i][k]+1);
		}
	}
	cout<<dp[a][b]<<endl;
	return 0;
}

