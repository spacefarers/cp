//
// Created by michaelyang on 12:00 PM Dec 29 2021.
// Problem: D. Keep the Average High

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
const int N=5e4+5;

int nums[N];
pair<int,pair<int,int>> dp[N][2];
int n,x;


int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>nums[i];
		}
		cin>>x;
		for (int i=1;i<=n;i++){
			nums[i]-=x;
		}
		for (int i=0;i<=n;i++){
			for (int j=0;j<2;j++){
				dp[i][j]={0,{0,0}};
			}
		}
		dp[0][0]={0,{0,0}};
		dp[0][1]={-1e9,{0,0}};
		for (int i=1;i<=n;i++){
			dp[i][0]={dp[i-1][1].f,{0,0}};
			if (dp[i-1][0].f>dp[i-1][1].f){
				dp[i][0]={dp[i-1][0].f,{0,0}};
			}
			dp[i][1]={dp[i-1][0].f+1,{0,nums[i]}};
			if (dp[i-1][1].s.s+nums[i]>=0&&dp[i-1][1].s.s+dp[i-1][1].s.f+nums[i]>=0){
				if (dp[i-1][1].f+1>dp[i][1].f){
					dp[i][1]={dp[i-1][1].f+1,{dp[i-1][1].s.s,nums[i]}};
				}
			}
		}
		cout<<max(dp[n][0].f,dp[n][1].f)<<endl;
	}
}