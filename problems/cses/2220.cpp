//
// Created by michaelyang on 5:27 PM Jan 01 2022.
// Problem: Counting Numbers

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=20;

ll dp[N][2][11]; // at where, tight?, ended with

ll find(ll x){
	vector<int> nums;
	for (auto &i:to_string(x)){
		nums.push_back(i-'0');
	}
	dp[0][0][10]=dp[0][1][10]=1;
	for (int i=1;i<=nums.size();i++){
		for (int l=0;l<11;l++){
			if (nums[i]==l) continue;
			dp[i][1][nums[i]]+=dp[i-1][1][l];
			dp[i][1][nums[i]]+=dp[i-1][0][l];
		}
		for (int k=0;k<10;k++){
			for (int j=0;j<11;j++){
				if (j==k) continue;
				dp[i][0][k]+=dp[i-1][1][j];
				dp[i][0][k]+=dp[i-1][0][j];
			}
		}
	}
	return dp[nums.size()][0][]
}

int main(){
	fastio
	ll a,b;
	cin>>a>>b;
	cout<<find(b)-find(a)<<endl;
}