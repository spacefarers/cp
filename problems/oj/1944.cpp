#include <iostream>

using namespace std;

int dp[25][25];

int main(){
	int n;
	cin>>n;
	dp[0][n-1]=1;
	dp[0][n-2]=1;
	for (int i=1;i<25;i++){
		for (int j=0;j<n;j++){
			dp[i][j]=dp[i-1][j+1]+dp[i-1][j+2];
		}
	}
	int ans=0;
	for (auto &i:dp){
		ans+=i[0];
	}
	cout<<ans<<endl;
}