//
// Created by michaelyang on 00:55 Dec 24 2021.
// Problem: D. Legacy

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define pi pair<ll,int>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int N=1e5+5;

int n,k,q,ind;
vector<pi> G[4*N];
pi track[4*N];
// a normal graph, where pi is {to where, cost}
// the first n represent the n nodes given, we are using k to keep track of adding new nodes
// the reason this is used instead of the old one is that we are needing a symmetrical tree up and down
// see https://robert1003.github.io/2020/02/14/graphs-and-segment-tree.html
ll dist[4*N];

pi build_tree(int tl=1,int tr=n){
	if (tl!=tr){
		int tm=(tl+tr)/2;
		int o1=k++,o2=k++;
		auto [l1,l2]=build_tree(tl,tm);
		auto [r1,r2]=build_tree(tm+1,tr);
		G[o1].emplace_back(0,l1);
		G[o1].emplace_back(0,r1);
		G[l2].emplace_back(0,o2);
		G[r2].emplace_back(0,o2);
		track[o1]={l1,r1};
		track[o2]={l2,r2};
		return {o1,o2};
	}
	return {tl,tl}; // important, links back to the start of the chain
}

void ins1(int from,int l,int r,ll c,int v=n+1,int tl=1,int tr=n){
	if (l<=tl&&tr<=r){
		G[from].emplace_back(c,v);
		return;
	} else{
		int mid=(tl+tr)/2;
		if (l<=mid) ins1(from,l,r,c,track[v].f,tl,mid);
		if (r>mid) ins1(from,l,r,c,track[v].s,mid+1,tr);
	}
}

void ins2(int to,int l,int r,ll c,int v=n+2,int tl=1,int tr=n){
	if (l<=tl&&tr<=r){
		G[v].emplace_back(c,to);
		return;
	} else{
		int mid=(tl+tr)/2;
		if (l<=mid) ins2(to,l,r,c,track[v].f,tl,mid);
		if (r>mid) ins2(to,l,r,c,track[v].s,mid+1,tr);
	}
}

int main(){
	fastio
	cin>>n>>q>>ind;
	k=n+1;
	memset(dist,0x7f,sizeof(dist));
	build_tree();
	while (q--){
		int t;
		cin>>t;
		if (t==1){
			int from,to,w;
			cin>>from>>to>>w;
			ins1(from,to,to,w);
		} else if (t==2){
			int from,tl,tr,w;
			cin>>from>>tl>>tr>>w;
			ins1(from,tl,tr,w);
		} else{
			int to,tl,tr,w;
			cin>>to>>tl>>tr>>w;
			ins2(to,tl,tr,w);
		}
	}
	// dijkstra
	priority_queue<pi,vector<pi>,greater<>> queue1;
	dist[ind]=0;
	queue1.push({0,ind});
	while (!queue1.empty()){
		auto u=queue1.top();
		queue1.pop();
		if (dist[u.s]!=u.f) continue;
		for (auto &i:G[u.s]){
			if (dist[i.s]>u.f+i.f){
				dist[i.s]=u.f+i.f;
				queue1.push({dist[i.s],i.s});
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<((dist[i]<1e12)?dist[i]:-1)<<" ";
	}
}