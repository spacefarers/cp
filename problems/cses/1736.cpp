//
// Created by michaelyang on 10:57 PM Jan 07 2022.
// Problem: Polynomial Queries
// Unfinished

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

ll tree[4*N],inputs[N];
ll lazy[4*N];
int n;

void build_tree(int v=1,int tl=1,int tr=n){
	if (tl==tr){
		tree[v]=inputs[tl];
	} else{
		int tm=(tl+tr)/2;
		build_tree(v*2,tl,tm);
		build_tree(v*2+1,tm+1,tr);
		tree[v]=tree[v*2]+tree[v*2+1];
	}
}

void propagate(int v,int tl,int tr){
	auto u=lazy[v];
	lazy[v]=0;
	ll tot=tr-tl+1;
	tree[v]+=tot*u;
	if (tl==tr) return;
	lazy[v*2]+=u;
	lazy[v*2+1]+=u;
}

void update_tree(int l,int r,ll c,int v=1,int tl=1,int tr=n){
	if (lazy[v]) propagate(v,tl,tr);
	if (tl>r||tr<l) return;
	if (tl>=l&&tr<=r){
		lazy[v]=c;
		propagate(v,tl,tr);
		return;
	}
	int m=(tr+tl)/2;
	update_tree(l,r,c,v*2,tl,m);
	update_tree(l,r,c+(m-tl),v*2+1,m+1,tr);
	tree[v]=tree[v*2]+tree[v*2+1];
}

ll get_sum(int l,int r,int v=1,int tl=1,int tr=n){
	if (lazy[v]) propagate(v,tl,tr);
	if (tl>r||tr<l) return 0;
	if (tl>=l&&tr<=r) return tree[v];
	int m=(tr+tl)/2;
	return get_sum(l,r,v*2,tl,m)+get_sum(l,r,v*2+1,m+1,tr);
}

int main(){
	fastio
	int q;
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>inputs[i];
	}
	build_tree();
	for (int i=0;i<q;i++){
		int x,a,b;
		cin>>x>>a>>b;
		if (x==1){
			update_tree(a,b,1);
		} else {
			cout<<get_sum(a,b)<<endl;
		}
	}
}