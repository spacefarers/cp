/*
ID: michael419
LANG: C++
TASK: tour
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

bool paths[105][105];
int dp[105][105];

int main(){
	setIO("tour");
	int n, m;
	cin>>n>>m;
	unordered_map<string, int> mp;
	for (int i=0;i<n;i++){
		string a;
		cin>>a;
		mp[a]=i;
	}
	for (int i=0;i<m;i++){
		string a, b;
		cin>>a>>b;
		paths[mp[a]][mp[b]]=true;
		paths[mp[b]][mp[a]]=true;
	}
	memset(dp, -0x3f, sizeof dp);
	dp[0][0]=1;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			for (int k=0;k<j;k++){
				if (!paths[k][j]||dp[i][k]<0) continue;
				dp[i][j]=dp[j][i]=max(dp[i][k]+1, dp[i][j]);
			}
		}
	}
	int ans=1;
	for (int i=0;i<n;i++){
		if (!paths[i][n-1]) continue;
		ans=max(ans, dp[i][n-1]);
	}
	cout<<ans<<endl;
}