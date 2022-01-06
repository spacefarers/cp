#include <iostream>

using namespace std;

int dp[505][505];

int main(){
	string a;
	cin>>a;
	int n=a.size();
	for (int i=0;i<=n;i++){
		for (int j=0;j<n;j++){
			dp[j][j+i]=dp[j+1][j+i]+1;
			for (int k=j+1;k<=i+j;k++){
				if (a[j]==a[k]){
					dp[j][j+i]=min(dp[j][j+i], dp[j+1][k-1]+dp[k+1][j+i]);
				}
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
}