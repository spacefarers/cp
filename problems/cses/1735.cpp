//
// Created by michaelyang on 9:52 PM Jan 07 2022.
// Problem: Range Updates and Sums
// 3/10
// Two Query Type Segment Tree
// 两种询问的线段树模板

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
const int N=2e5+5;

ll tree[4*N],inputs[N];
pair<ll,int> lazy[4*N]; // amount, type: 1-add,2-set
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
	lazy[v]={0,0};
	ll tot=tr-tl+1;
	if (u.s==1) tree[v]+=tot*u.f;
	else tree[v]=tot*u.f;
	if (tl==tr) return;
	if (u.s==1&&lazy[v*2].s) lazy[v*2].f+=u.f;
	else lazy[v*2]=u;
	if (u.s==1&&lazy[v*2+1].s) lazy[v*2+1].f+=u.f;
	else lazy[v*2+1]=u;
}

void update_tree(int l,int r,ll c,int t,int v=1,int tl=1,int tr=n){
	if (lazy[v].s) propagate(v,tl,tr);
	if (tl>r||tr<l) return;
	if (tl>=l&&tr<=r){
		lazy[v]={c,t};
		propagate(v,tl,tr);
		return;
	}
	int m=(tr+tl)/2;
	update_tree(l,r,c,t,v*2,tl,m);
	update_tree(l,r,c,t,v*2+1,m+1,tr);
	tree[v]=tree[v*2]+tree[v*2+1];
}

ll get_sum(int l,int r,int v=1,int tl=1,int tr=n){
	if (lazy[v].s) propagate(v,tl,tr);
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
		int x;
		cin>>x;
		if (x==1||x==2){
			int a,b,c;
			cin>>a>>b>>c;
			update_tree(a,b,c,x);
		} else{
			int a,b;
			cin>>a>>b;
			cout<<get_sum(a,b)<<endl;
		}
	}
}