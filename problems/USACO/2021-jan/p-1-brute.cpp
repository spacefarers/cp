//
// Created by michaelyang on 11:39 PM Jan 07 2022.
// Problem: Problem 1. Sum of Distances

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

struct Graph{
	vector<vector<int>> adj;
};

vector<Graph> graphs;

vector<vector<int>> opts;
vector<int> c;
int k;
map<vector<int>,bool> mp;

void generateOptions(vector<int> state){
	if (c.size()==k){
		if (!mp[c]) opts.push_back(c);
		mp[c]=true;
		return;
	}
	int p=c.size();
	for (auto &i:graphs[p].adj[state[p]]){
		c.push_back(i);
		generateOptions(state);
		c.pop_back();
	}
}

int main(){
	fastio
	cin>>k;
	graphs.resize(k);
	for (int i=0;i<k;i++){
		int n,m;
		cin>>n>>m;
		graphs[i].adj.resize(n+1);
		for (int j=0;j<m;j++){
			int a,b;
			cin>>a>>b;
			graphs[i].adj[a].push_back(b);
			graphs[i].adj[b].push_back(a);
		}
	}
	vector<int> state(k,1);
	ll ans=0;
	mp[state]=true;
	queue<vector<int>> queue1;
	queue1.push(state);
	int stage=1;
	while (!queue1.empty()){
		int p=queue1.size();
		for (int i=0;i<p;i++){
			auto u=queue1.front();
			queue1.pop();
			generateOptions(u);
			for (auto &j:opts){
				ans+=stage;
				queue1.push(j);
			}
			opts.clear();
		}
		stage++;
	}
	cout<<ans<<endl;
}