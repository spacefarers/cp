#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000005], mod=1e9+7, coins[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin>>n>>x;
	for (int i=0;i<n;i++){
		cin>>coins[i];
	}
	dp[0]=1;
	for (int j=0;j<n;j++){
		for (int i=1;i<=x;i++){
			if (coins[j]<=i)
				dp[i]=(dp[i]+dp[i-coins[j]])%mod;
		}
	}
	cout<<dp[x]<<endl;
	return 0;
}