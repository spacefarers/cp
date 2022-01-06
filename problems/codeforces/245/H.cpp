//
// Created by spacefarers on 8:14 PM Nov 21 2021.
// Problem: H. Queries for Number of Palindromes

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

int dp[5005][5005];
bool ans[5005][5005];
int n;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
//	freopen("input.txt","r",stdin);
	string x;
	cin>>x;
	n=(int)x.size();
	for (int i=n-1;i>=0;i--){
		for (int j=i;j<n;j++){
			ans[i][j]=(x[i]==x[j])&&(ans[i+1][j-1]||i+1>j-1);
			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+ans[i][j];
		}
	}
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		cout<<dp[a][b]<<'\n';
	}
}