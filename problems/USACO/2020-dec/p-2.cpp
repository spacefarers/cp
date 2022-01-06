//
// Created by spacefarers on 9:15 PM Nov 20 2021.
// Problem: Spaceship

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

vector<int> paths[65];
int N,K,Q;
ll dp[100][65];

void dfs(int stat,int cPos){
	for (auto&i:paths[cPos]){
		for (int j=0;j<K;j++){
			if (stat>>j&0){
				auto newStat=stat;
				for (int k=0;k<j;k++){
					newStat=(newStat&~(1<<k))|(0<<k);
				}
				newStat=(newStat&~(1<<j))|(1<<j);
				dp[newStat][i]++;

			}
		}
	}
}

int main(){
	cin>>N>>K>>Q;
	for (int i=0;i<N;i++){
		string x;
		cin>>x;
		for (int j=0;j<N;j++){
			if (x[j]=='1'){
				paths[i+1].push_back(j+1);
			}
		}
	}
	for (int i=0;i<Q;i++){
		int bs,s,bt,t;
		cin>>bs>>s>>bt>>t;
		memset(dp,0,sizeof dp);

	}
}

