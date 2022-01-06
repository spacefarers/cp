#include <iostream>

using namespace std;

#define ll long long

ll dp[405][405];
int MOD;
ll NCR[505][505],pow2[505];

void precomp(){
    NCR[0][0]=1;
	for (int i=1;i<505;i++){
	    NCR[i][0]=NCR[i][i]=1;
		for (int j=1;j<i;j++){
			NCR[i][j]=NCR[i-1][j-1]+NCR[i-1][j];
			NCR[i][j]%=MOD;
		}
	}
	pow2[0]=1;
    for (int i=1;i<505;i++){
        pow2[i]=pow2[i-1]*2;
        pow2[i]%=MOD;
    }
}

int main(){
	int n;
	cin>>n>>MOD;
	precomp();
	dp[0][0]=1;
	for (int i=0;i<n;i++){
		for (int j=0;j<=i;j++){
			for (int k=1;k<=n-i;k++){
				dp[i+k+1][j+k]+=((dp[i][j]*NCR[j+k][k])%MOD)*pow2[k-1];
				dp[i+k+1][j+k]%=MOD;
			}
		}
	}
	ll ans=0;
	for (int i=0;i<=n;i++){
		ans+=dp[n+1][i];
		ans%=MOD;
	}
	cout<<ans<<endl;
}