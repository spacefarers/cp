//
// Created by spacefarers on 4:46 PM Nov 21 2021.
// Problem: D. Eternal Victory

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

#define f first
#define s second
#define ll long long

using namespace std;

vector<pair<int,ll>> paths[100005];
ll mostExp[100005];
set<int> vis;

ll totCost=0;

void dfs(int x,ll cost,int par){
	vis.erase(x);
	for (auto&i:paths[x]){
		if (i.f==par) continue;
		totCost+=2*i.s;
		mostExp[i.f]=max(mostExp[i.f],mostExp[x]+i.s);
		dfs(i.f,i.s,x);
	}
}

int main(){
	int n;
	cin>>n;
	for (int i=0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].emplace_back(b,c);
		paths[b].emplace_back(a,c);
	}
	for (int i=1;i<=n;i++){
		vis.insert(i);
	}
	dfs(1,0,-1);
	cout<<totCost-*max_element(mostExp+1,mostExp+n+1)<<endl;
}

