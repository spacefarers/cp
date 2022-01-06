#include <iostream>
#include <vector>

using namespace std;

int dp[305][305];

int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	for (int i=n;i>=0;i--){
		for (int j=i+1;j<n;j++){
			if (nums[i]==nums[j]) dp[i][j]=max(dp[i][j], dp[i+1][j-1]+1);
			for (int k=i;k<=j;k++){
				dp[i][j]=max(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
	cout<<n-dp[0][n-1]<<endl;
}