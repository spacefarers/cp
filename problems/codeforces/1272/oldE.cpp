//
// Created by spacefarers on 4:31 PM Nov 25 2021.
// Problem: E. Nearest Opposite Parity

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

int a[200005],dp[200005];
bool vis[200005];
int n;

bool check(int i,int j){
	return a[i]%2!=a[j]%2;
}

int find(int x){
	if (vis[x]){
		int newAns=-1;
		int opt1=-1,opt2=-1;
		if (x-a[x]>=0) opt1=dp[x-a[x]];
		if (x+a[x]<n) opt2=dp[x+a[x]];
		if (opt1==-1) newAns=opt2;
		else if (opt2==-1) newAns=opt1;
		else newAns=min(opt1,opt2);
		if (newAns!=-1){
			newAns++;
			if (dp[x]>newAns||dp[x]==-1)
				dp[x]=newAns;
		}
		return dp[x];
	}
	vis[x]=true;
	if (x-a[x]>=0&&check(x,x-a[x])||x+a[x]<n&&check(x,x+a[x])) dp[x]=1;
	else{
		int opt1=-1,opt2=-1;
		if (x-a[x]>=0) opt1=find(x-a[x]);
		if (x+a[x]<n) opt2=find(x+a[x]);
		if (opt1==-1) dp[x]=opt2;
		else if (opt2==-1) dp[x]=opt1;
		else dp[x]=min(opt1,opt2);
		if (dp[x]!=-1) dp[x]++;
	}
	return dp[x];
}

int main(){
	fastio
	cin>>n;
	memset(dp,-1,sizeof dp);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cout<<find(i)<<" ";
	}
}

