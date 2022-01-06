//
// Created by michaelyang on 6:33 PM Jan 01 2022.
// Problem: Counting Tilings

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
const int N=1005;

int dp[1<<10],newDP[1<<10];
int n,m;

map<int,set<int>> mp;

void gen(int from,int x,int next){
	if (x==n){
		mp[next].insert(from);
		return;
	}
	if (from&1<<x){
		gen(from,x+1,next);
		return;
	}
	// put vertical
	if (x<n-1&&(!(from&1<<(x+1)))){
		gen(from,x+2,next);
	}
	next+=(1<<x);
	gen(from,x+1,next);
}

int main(){
	fastio
	cin>>n>>m;
	for (int i=0;i<=1<<n;i++){
		gen(i,0,0);
	}
	dp[0]=1;
	for (int i=0;i<m;i++){
		for (int j=0;j<1<<n;j++){
			for (auto &k:mp[j]){
				newDP[j]+=dp[k];
				newDP[j]%=MOD;
			}
		}
		swap(newDP,dp);
		memset(newDP,0,sizeof newDP);
	}
	cout<<dp[0]<<endl;
}