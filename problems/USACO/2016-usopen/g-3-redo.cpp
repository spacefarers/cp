// 248 range dp

#include <iostream>
#include <vector>

using namespace std;

int dp[300][300];

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("248");
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>dp[i][i];
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<n-i;j++){
			for (int k=j;k<j+i;k++){
				if (dp[j][k]==dp[k+1][j+i]){
					dp[j][j+i]=max(dp[j][j+i], dp[j][k]+1);
				}
			}
			ans=max(ans, dp[j][j+i]);
		}
	}
	cout<<ans<<endl;
}