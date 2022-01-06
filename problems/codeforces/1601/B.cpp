//
// Created by spacefarers on 10:02 PM Nov 20 2021.
// Problem: B. Frog Traveler

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define f first
#define s second
#define ll long long

using namespace std;


int tree[1200005],lazy[1200005];
int jump[300005],slip[300005];
int n;
priority_queue<pair<int,int>> q;

void propagate(int v,int tl,int tr,int m){
	tree[v*2]=lazy[v],tree[v*2+1]=lazy[v];
	lazy[v*2]=lazy[v];
	lazy[v*2+1]=lazy[v];
	lazy[v]=0;
}

void update_tree(int l,int r,int c,int v=1,int tl=1,int tr=n){
	if (l<=tl&&tr<=r){
		tree[v]=c;
		lazy[v]=c;
		return;
	}
	int m=(tr+tl)/2;
	if (lazy[v]&&tl!=tr) propagate(v,tl,tr,m);
	if (l<=m) update_tree(l,r,c,v*2,tl,m);
	if (r>m) update_tree(l,r,c,v*2+1,m+1,tr);
	tree[v]=min(tree[v*2],tree[v*2+1]);
}

int get_min(int l,int r,int v=1,int tl=1,int tr=n){
	if (l<=tl&&tr<=r) return tree[v];
	int m=(tr+tl)/2;
	int ans=1e9;
	if (lazy[v]) propagate(v,tl,tr,m);
	if (l<=m) ans=min(ans,get_min(l,r,v*2,tl,m));
	if (r>m) ans=min(ans,get_min(l,r,v*2+1,m+1,tr));
	return ans;
}

int main(){
	memset(tree,0x3f,sizeof tree);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>jump[i];
	}
	for (int i=1;i<=n;i++){
		cin>>slip[i];
	}
	update_tree(n,n,0);
	q.push({0,n});
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (u.f!=get_min(u.s,u.s)) continue;
		int slipped=u.s-slip[u.s];
		update_tree(slipped,jump[slipped],u.f+1);
	}
}

