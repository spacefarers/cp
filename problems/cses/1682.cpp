//
// Created by michaelyang on 11:38 PM Jan 01 2022.
// Problem: Flight Routes Check
// Strongly Connected Components

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

vector<int> paths[N],revPaths[N];
bool used[N],reachableFromP[N];
vector<int> order;

void dfs1(int x){
	used[x]=true;
	for (auto &i:paths[x]){
		if (!used[i]) dfs1(i);
	}
	order.push_back(x);
}

void dfs2(int x){
	used[x]=true;
	for (auto &i:revPaths[x]){
		if (!used[i]) dfs2(i);
	}
}

void dfs3(int x){
	if (reachableFromP[x]) return;
	reachableFromP[x]=true;
	for (auto &i:paths[x]){
		dfs3(i);
	}
}

int main(){
	fastio
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		revPaths[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		if (!used[i]) dfs1(i);
	}
	memset(used,false,sizeof used);
	reverse(order.begin(),order.end());
	int p=order.front();
	dfs2(p);
	dfs3(p);
	for (int i=1;i<=n;i++){
		if (!used[i]){
			cout<<"NO"<<endl;
			if (reachableFromP[i]){
				cout<<i<<" "<<p<<endl;
			} else {
				cout<<p<<" "<<i<<endl;
			}
			return 0;
		}
	}
	cout<<"YES"<<endl;
}