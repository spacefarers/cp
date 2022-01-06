#include <iostream>

using namespace std;

int dp[15][15];

int solve(int m, int n){
	if (dp[m][n]) return dp[m][n];
	if (n<=0||m<0) return 0;
	if (m==1||n==1||m==0) return 1;
	int ans;
	if (m<n) ans=solve(m, m);
	else ans=solve(m, n-1)+solve(m-n, n);
	dp[m][n]=ans;
	return ans;
}

int main(){
	int n;
	cin>>n;
	solve(11,11);
	for (int i=0;i<n;i++){
		int a, b;
		cin>>a>>b;
		cout<<solve(a,b)<<endl;
	}
}