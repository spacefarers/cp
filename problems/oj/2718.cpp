#include <iostream>

using namespace std;

int dp[25][25];

int main(){
	int m, n;
	cin>>m>>n;
	dp[0][1]=1;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[m][n]<<endl;
}