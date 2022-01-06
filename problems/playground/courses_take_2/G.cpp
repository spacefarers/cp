#include <iostream>
#include <vector>

using namespace std;

int dp[500005];

int main(){
	int n, m;
	cin>>n>>m;
	vector<int> money;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		money.push_back(a);
	}
	dp[0]=1;
	for (auto &i:money){
		for (int j=0;j<=m;j++){
			if (j-i>=0) dp[j]+=dp[j-i];
		}
	}
	cout<<dp[m]<<endl;
}