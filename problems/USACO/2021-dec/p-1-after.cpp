//
// Created by michaelyang on 00:48 Dec 24 2021.
// Problem: Problem 1. Tickets
// Related Problem: codeforces/787/D
// segment tree on graphs

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
int const N=1e5+5;

int MOD=1e9+7,n,k,q,t;
pl track[4*N];
vector<pl> G[4*N];
ll distOne[4*N],distN[4*N],distAns[4*N];

int build_tree(int tl=1,int tr=n){
	if (tl!=tr){
		int o=k++;
		int mid=(tl+tr)/2;
		int l=build_tree(tl,mid);
		int r=build_tree(mid+1,tr);
		G[l].emplace_back(0,o); // if range to point, graph is moving up
		G[r].emplace_back(0,o);
		track[o]={l,r};
		return o;
	}
	return tl;
}

void ins(int to,int l,int r,ll c,int v=n+1,int tl=1,int tr=n){
	if (l<=tl&&tr<=r){
		G[v].emplace_back(c,to);
		return;
	}
	int mid=(tr+tl)/2;
	if (l<=mid) ins(to,l,r,c,track[v].f,tl,mid);
	if (r>mid) ins(to,l,r,c,track[v].s,mid+1,tr);
}

void dijkstra(int source,ll *arr){
	priority_queue<pl,vector<pl>,greater<>> queue1;
	arr[source]=0;
	queue1.push({0,source});
	while (!queue1.empty()){
		auto u=queue1.top();
		queue1.pop();
		if (arr[u.s]!=u.f) continue;
		for (auto &i:G[u.s]){
			if (arr[i.s]>i.f+u.f||arr[i.s]==-1){
				arr[i.s]=i.f+u.f;
				queue1.push({arr[i.s],i.s});
			}
		}
	}
}

int main(){
	fastio
	memset(distOne,-1,sizeof distOne);
	memset(distN,-1,sizeof distN);
	memset(distAns,-1,sizeof distAns);
	cin>>n>>q;
	k=n+1;
	build_tree();
	t=k;
	while (q--){
		int to,w,tl,tr;
		cin>>to>>w>>tl>>tr;
		G[k].emplace_back(w,to);
		ins(k,tl,tr,0);
		k++;
	}
	dijkstra(1,distOne);
	dijkstra(n,distN);
	for (int i=1;i<k;i++){
		if (distOne[i]==-1||distN[i]==-1) continue;
		G[k].emplace_back(distOne[i]+distN[i],i);
		if (i==n) i=t;
	}
	dijkstra(k,distAns);
	for (int i=1;i<=n;i++){
		cout<<distAns[i]<<endl;
	}
}