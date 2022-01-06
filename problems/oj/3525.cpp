#include <iostream>

using namespace std;

long long dp[105];

int main(){
	int x;
	dp[0]=1;
	for (int i=1;i<105;i++){
		for (int j=1;j<=3;j++){
			if (i-j>=0) dp[i]+=dp[i-j];
		}
	}
	while (cin>>x&&x!=0){
		cout<<dp[x]<<endl;
	}
}