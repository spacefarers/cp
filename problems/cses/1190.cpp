//
// Created by michaelyang on 12:24 AM Jan 07 2022.
// Problem: Subarray Sum Queries
// 5/10

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <array>
#include <map>

#define f first
#define s second
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=2e5+5;

array<ll,4> tree[4*N]; // max subarray sum, max subsum include left, max subsum include right, total sum
int n,inputs[N];

void propagate(int v){
	tree[v][0]=max(max(tree[v*2][0],tree[v*2+1][0]),tree[v*2][2]+tree[v*2+1][1]);
	tree[v][1]=max(tree[v*2][1],tree[v*2][3]+tree[v*2+1][1]);
	tree[v][2]=max(tree[v*2+1][2],tree[v*2+1][3]+tree[v*2][2]);
	tree[v][3]=tree[v*2][3]+tree[v*2+1][3];
	for (int i=1;i<=3;i++) tree[v][0]=max(tree[v][0],tree[v][i]);
}

void build_tree(int v=1, int tl=1, int tr=n){
	if (tl==tr){
		for (int i=0;i<4;i++){
			tree[v][i]=inputs[tl];
		}
	} else {
		int tm=(tl+tr)/2;
		build_tree(v*2, tl, tm);
		build_tree(v*2+1, tm+1, tr);
		propagate(v);
	}
}


void update_tree(int p,ll c,int v=1,int tl=1,int tr=n){
	if (p<=tl&&tr<=p){
		for (int i=0;i<4;i++){
			tree[v][i]=c;
		}
		return;
	}
	int m=(tr+tl)/2;
	if (p<=m) update_tree(p,c,v*2,tl,m);
	if (p>m) update_tree(p,c,v*2+1,m+1,tr);
	propagate(v);
}

int main(){
	fastio
	int m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>inputs[i];
	}
	build_tree();
	for (int i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		update_tree(a,b);
		cout<<max(tree[1][0],(ll)0)<<endl;
	}
}