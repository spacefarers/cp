//
// Created by spacefarers on 1:24 AM Dec 22 2021.
// Problem: Sprinklers 2: Return of the Alfalfa

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

ll MOD=1e9+7;

ll dp[2005][2005][2]; // 0: horiz 1: vert
string board[2005];
int numAvail[2005];
ll power[2005];

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("sprinklers2");
	int n;
	cin>>n;
	power[0]=1;
	for (int i=1;i<2005;i++){
		power[i]=power[i-1]*2;
		power[i]%=MOD;
	}
	for (int i=1;i<=n;i++){
		cin>>board[i];
		board[i]='W'+board[i];
		for (int j=1;j<=n;j++){
			if (board[i][j]=='.')
				numAvail[i]++;
		}
	}
	dp[0][0][0]=1;
	dp[0][0][1]=1;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			if (i==0&&j==0) continue;
			if (i>0){
				ll multiplier=power[numAvail[i]];
				dp[i][j][1]=((board[i][j]=='.')*((multiplier*dp[i-1][j][0])%MOD*500000004)%MOD+multiplier*dp[i-1][j][1]);
				dp[i][j][1]%=MOD;
			}
			if (j>0){
				dp[i][j][0]=(board[i][j]=='.')*(dp[i][j-1][1]*500000004)%MOD+dp[i][j-1][0];
				dp[i][j][0]%=MOD;
			}
		}
	}
	cout<<(dp[n][n][0]+dp[n][n][1])%MOD<<endl;

	if (i>0){
		ll multiplier=power[numAvail[i]];
		dp[i][j][1]=((board[i][j]=='.')*((multiplier*dp[i-1][j][0])%MOD*500000004)%MOD+multiplier*dp[i-1][j][1]);
		dp[i][j][1]%=MOD;
	}
	if (j>0){
		dp[i][j][0]=(board[i][j]=='.')*(dp[i][j-1][1]*500000004)%MOD+dp[i][j-1][0];
		dp[i][j][0]%=MOD;
	}
}

