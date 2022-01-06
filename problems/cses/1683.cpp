//
// Created by michaelyang on 12:42 AM Jan 02 2022.
// Problem: Planets and Kingdoms

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
const int N=1e5+5;

vector<int> G[N],revG[N];
bool used[N];
vector<int> order,components;
int who[N];

void dfs1(int x){
	if (used[x]) return;
	used[x]=true;
	for (auto &i:G[x]){
		dfs1(i);
	}
	order.push_back(x);
}

void dfs2(int k,int x){
	if (used[x]) return;
	used[x]=true;
	who[x]=k;
	for (auto &i:revG[x]){
		dfs2(k,i);
	}
}

int main(){
	fastio
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		revG[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		dfs1(i);
	}
	reverse(order.begin(),order.end());
	memset(used,false,sizeof used);
	int k=1;
	for (auto &i:order){
		if (!used[i]){
			dfs2(k++,i);
		}
	}
	cout<<k-1<<endl;
	for (int i=1;i<=n;i++){
		cout<<who[i]<<" ";
	}
}