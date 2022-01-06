#include <iostream>

using namespace std;

int nums[305],dp[305][305];

int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>nums[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n-i;j++){
//			dp[j][j+i]=dp[j+1][j+i]+1;
			if (nums[j]==nums[j+i]) dp[j][j+i]=dp[j+1][j+i-1]+1;
			for (int k=j+1;k<=j+i;k++){
				dp[j][j+i]=max(dp[j][j+i],dp[j][k]+dp[k+1][j+i]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
}