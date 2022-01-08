//
// Created by michaelyang on 11:54 PM Jan 06 2022.
// Problem: Pizzeria Queries

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

int tree1[3*N],tree2[3*N],n,inputs[N],lazy1[3*N],lazy2[3*N]; // tree 1 goes down, tree 2 goes up

void build_tree(int *tree,bool up,int tl=1,int tr=n,int c=1){
	if (tl==tr){
		tree[c]=inputs[tl];
		if (up) tree[c]+=tl;
		else tree[c]-=tl;
	} else {
		int mid=(tl+tr)/2;
		build_tree(tree,up,tl,mid,c*2);
		build_tree(tree,up,mid+1,tr,c*2+1);
		tree[c]=min(tree[c*2],tree[c*2+1]);
	}
}

void propagate(int *lazy,int *tree,int v,int tl,int tr,int m){
	tree[v*2]=lazy[v],tree[v*2+1]=lazy[v];
	lazy[v*2]=lazy[v];
	lazy[v*2+1]=lazy[v];
	lazy[v]=0;
}

void update_tree(int *tree,int *lazy,int l,int r,int x,int c=1,int tl=1,int tr=n){
	if (l<=tl&&tr<=r){
		tree[c]=x;
		lazy[c]=x;
	} else {
		int mid=(tl+tr)/2;
		if (lazy[c]&&tl!=tr) propagate(lazy,tree,x,tl,tr,mid);
		if (l<=mid) update_tree(tree,lazy,l,r,x,c*2,tl,mid);
		if (r>mid) update_tree(tree,lazy,l,r,x,c*2+1,mid+1,tr);
		tree[c]=min(tree[c*2],tree[c*2+1]);
	}
}

int get_min(int *tree,int *lazy,int l,int r,int v=1,int tl=1,int tr=n){
	if (l<=tl&&tr<=r) return tree[v];
	int m=(tr+tl)/2;
	int ans=1e9;
	if (lazy[v]) propagate(lazy,tree,v,tl,tr,m);
	if (l<=m) ans=min(ans,get_min(tree,lazy,l,r,v*2,tl,m));
	if (r>m) ans=min(ans,get_min(tree,lazy,l,r,v*2+1,m+1,tr));
	return ans;
}

int main(){
	fastio
	int q;
	cin>>n>>q;
	memset(tree1,0x3f,sizeof tree1);
	memset(tree2,0x3f,sizeof tree2);
	for (int i=1;i<=n;i++){
		cin>>inputs[i];
	}
	build_tree(tree1,false);
	build_tree(tree2,true);
	for (int i=0;i<q;i++){
		int a;
		cin>>a;
		if (a==1){
			int b,c;
			cin>>b>>c;
			update_tree(tree1,lazy1,b,b,c-b);
			update_tree(tree2,lazy2,b,b,c+b);
		} else {
			int b;
			cin>>b;
			int downMin=get_min(tree1,lazy1,1,b)+b;
			int upMin=get_min(tree2,lazy2,b,n)-b;
			cout<<min(downMin,upMin)<<endl;
		}
	}
}