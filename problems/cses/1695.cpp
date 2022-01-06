//
// Created by michaelyang on 4:00 PM Jan 02 2022.
// Problem: Police Chase

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

int n,m,source,sink;

struct Edge{
	int from,to,flow,cap;
	Edge *rev;

	Edge(int from,int to,int flow,int cap):from(from),to(to),flow(flow),cap(cap){}
};

vector<Edge> G[N];
void addEdge(int a,int b,int cap){
	Edge e(a,b,0,cap);
	Edge revEdge(b,a,0,0);
	e.rev=&revEdge,revEdge.rev=&e;
	G[a].push_back(e);
	G[b].push_back(revEdge);
}

bool bfs(){
	queue<int> queue1;
	while (!queue1.empty()){

	}
}

ll dinic(){

}

int main(){
	fastio
	cin>>n>>m;
	source=1,sink=n;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		addEdge(a,b,1);
	}
}