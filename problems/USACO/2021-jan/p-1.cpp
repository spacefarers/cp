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
int k,reachedOne[N];
ll ans[N];

set<int> bfs(int g,set<int> covered){
	set<int> newCovered;
	for (auto &i:covered){
		for (auto &j:graphs[g].adj[i]){
			newCovered.insert(j);
		}
	}
	return newCovered;
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
	int maxDep=0;
	for (int i=0;i<k;i++){
		set<int> covered;
		covered.insert(1);
		map<set<int>,int> mp;
		vector<pair<int,int>> store(1);
		int st=1;
		int rep=-1;
		while (true){
			covered=bfs(i,covered);
			if (mp.find(covered)!=mp.end()){
				rep=mp[covered];
				break;
			}
			if (ans[st]==0&&i==0) ans[st]=1;
			store.push_back({covered.size(),0});
			ans[st]*=covered.size();
			if (covered.find(1)!=covered.end()){
				reachedOne[st]++;
				store.back().s++;
			}
			ans[st]%=MOD;
			mp[covered]=st;
			st++;
		}
		int bp=st;
		maxDep=max(maxDep,st-1);
		int c=rep;
		for (;st<N;st++){
			if (ans[st]==0&&i==0) ans[st]=1;
			ans[st]*=store[c].f;
			reachedOne[st]+=store[c].s;
			ans[st]%=MOD;
			c++;
			if (c==bp) c=rep;
		}
	}
	ll f_ans=0;
	for (int i=0;i<=maxDep;i++){
		if (reachedOne[i]==k) ans[i]--;
		f_ans+=i*ans[i];
		f_ans%=MOD;
	}
	cout<<f_ans<<endl;
}