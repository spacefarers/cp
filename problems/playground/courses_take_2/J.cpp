#include <iostream>

using namespace std;

int m, n, sit[5000], sta[5000], cnt=0,dp[15][5000],MOD=1e8,no_plant[15];

void dfs(int x, int num, int cur){
	if (cur>=n){
		sit[cnt]=x;
		sta[cnt++]=num;
		return;
	}
	dfs(x,num,cur+1);
	dfs(x+(1<<cur),num+1,cur+2);
}

int main(){
	cin>>m>>n;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			int a;
			cin>>a;
			no_plant[i]+=(1<<j)*(1-a);
		}
	}
	dfs(0,0,0);
	for (int i=0;i<cnt;i++){
		if (sit[i]&no_plant[0]) continue;
		dp[0][i]=1;
	}
	for (int i=1;i<m;i++){
		for (int j=0;j<cnt;j++){
			if (sit[j]&no_plant[i]) continue;
			for (int k=0;k<cnt;k++){
				if (sit[k]&no_plant[i-1]) continue;
				if (sit[j]&sit[k]) continue;
				dp[i][j]+=dp[i-1][k];
				dp[i][j]%=MOD;
			}
		}
	}
	int ans=0;
	for (int i=0;i<cnt;i++){
		ans+=dp[m-1][i];
		ans%=MOD;
	}
	cout<<ans<<endl;
}