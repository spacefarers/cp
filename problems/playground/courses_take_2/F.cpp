#include <iostream>

using namespace std;

int dp[15][20], c[15][20], ans[20];

int main(){
	int n, m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<=j;k++){
				dp[i][j]=max(dp[i][j],dp[i-1][k]+c[i][j-k]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
	int remain=m;
	for (int i=n;i>0;i--){
		for (int j=0;j<=remain;j++){
			if (dp[i-1][j]+c[i][remain-j]==dp[i][remain]){
				j=remain-j;
				ans[i]=j;
				remain-=j;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
}