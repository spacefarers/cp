#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[10005][2005];
int low[10005],high[10005],x[10005],y[10005];
bool e[10005];
int main()
{
	int n, m, p;
	cin>>n>>m>>p;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		low[i]=1;high[i]=m;
	}
	for(int i=1;i<=p;i++){
		int a, b, c;
		cin>>a>>b>>c;
		low[a]=b+1;
		high[a]=c-1;
		e[a]=true;
	}
	memset(dp, 0x3f, sizeof dp);
	for(int i=1;i<=m;i++) dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=x[i]+1;j<=m+x[i];j++)
			dp[i][j]=min(dp[i-1][j-x[i]]+1,dp[i][j-x[i]]+1);
		for(int j=m+1;j<=m+x[i];j++)
			dp[i][m]=min(dp[i][m],dp[i][j]);
		for(int j=1;j<=m-y[i];j++)
			dp[i][j]=min(dp[i][j],dp[i-1][j+y[i]]);
		for(int j=1;j<low[i];j++)
			dp[i][j]=dp[0][0];
		for(int j=high[i]+1;j<=m;j++)
			dp[i][j]=dp[0][0];
	}
	int ans=dp[0][0];
	for (int j=1;j<=m;j++) ans=min(ans,dp[n][j]);
	if(ans<dp[0][0]) cout<<1<<endl<<ans<<endl;
	else {
		int c=0;
		for (int i=1;i<=n;i++){
			if (!e[i]) continue;
			int temp=dp[0][0];
			for (int j=1;j<=m;j++){
				temp=min(temp, dp[i][j]);
			}
			if (temp==dp[0][0]){
				cout<<0<<endl<<c<<endl;
				exit(0);
			}
			c++;
		}
		cout<<0<<endl<<p<<endl;
	}
}