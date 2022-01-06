#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool dp[1005];

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(dp, false, sizeof dp);
		int n, k;
		cin>>n>>k;
		dp[0]=true;
		vector<int> ans;
		for (int i=n;i>0;i--){
			if (k-i>=0&&dp[k-i]) continue;
			ans.push_back(i);
			for (int j=1;j<=k;j++){
				if (j-i>=0&&dp[j-i]) dp[j]=true;
			}
		}
		cout<<ans.size()<<endl;
		for (auto &i:ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}