/*
ID: michael419
LANG: C++
TASK: bigbrn
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

int dp[1005][1005];

int main(){
	setIO("bigbrn");
	int N, T;
	cin>>N>>T;
	for (int i=0;i<T;i++){
		int a, b;
		cin>>a>>b;
		dp[a][b]=-1;
	}
	int ans=0;
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			if (dp[i][j]==-1){
				dp[i][j]=0;continue;
			}
			dp[i][j]=min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
			ans=max(ans, dp[i][j]);
		}
	}
	cout<<ans<<endl;
}