//
// Created by michaelyang on 10:20 PM Dec 25 2021.
// Problem: Download Speed
// Dinic's Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define pl pair<ll,ll>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=1e5+5;

int level[N],source,sink;

struct Edge{
	int to;
	ll flow,cap;
	Edge *rev;
	Edge(ll to,ll flow,ll cap):to(to),flow(flow),cap(cap){}
};

vector<Edge> G[N];

void addEdge(int from,int to,ll cap){
	Edge edge{to,0,cap},revEdge{from,0,0};
	edge.rev=&revEdge;
	revEdge.rev=&edge;
	G[from].push_back(edge);
	G[to].push_back(revEdge);
}

bool bfs(){
	memset(level,-1,sizeof level);
	queue<int> queue1;
	queue1.push(source);
	level[source]=0;
	while (!queue1.empty()){
		auto u=queue1.front();
		queue1.pop();
		for (auto &i:G[u]){
			if (level[i.to]==-1&&i.flow<i.cap){
				level[i.to]=level[u]+1;
				queue1.push(i.to);
			}
		}
	}
	return level[sink]!=-1;
}

ll dfs(int u=source,ll flow=1e9){
	if (u==sink) return flow;
	for (auto &i:G[u]){
		if (level[i.to]==level[u]+1&&i.flow<i.cap){
			ll newFlow=dfs(i.to,min(i.cap-i.flow,flow));
			if (newFlow>0){
				i.flow+=newFlow;
				i.rev->flow-=newFlow;
				return newFlow;
			}
		}
	}
	return 0;
}

ll dinic(){
	ll tot=0;
	while (bfs())
		while (ll flow=dfs())
			tot+=flow;
	return tot;
}

int main(){
	fastio
	int n,q;
	cin>>n>>q;
	// Set Source and Sink here, IMPORTANT
	source=1;
	sink=n;
	for (int i=0;i<q;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		addEdge(a,b,c);
	}
	cout<<dinic()<<endl;
}