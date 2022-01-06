#include <iostream>
#include <cstring>

using namespace std;

#define ll long long

ll dp[1005][1005];
int N,K,called=0;

int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>N>>K;
		memset(dp,0,sizeof dp);
		for (int i=0;i<=N;i++){
			dp[1][i]=1;
		}
		for (int j=2;j<=K;j++){
			dp[j][0]++;
			for (int i=1;i<=N;i++){
				dp[j][0]+=dp[j-1][i];
				dp[j][0]%=(ll)(1e9+7);
			}
			for (int i=1;i<=N;i++){
				dp[j][i]=dp[j][i-1]-dp[j-1][N-i+1];
				dp[j][i]+=1e9+7;
				dp[j][i]%=(ll)(1e9+7);
			}
		}
		cout<<dp[K][0]<<endl;
	}
}