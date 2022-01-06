//
// Created by spacefarers on 11:21 PM Nov 27 2021.
// Problem: Hotel Queries

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int input[200005],tree[800005],lazy[800005];
int n;

void build_tree(int s=1,int t=n,int p=1){
	if (s==t){
		tree[p]=input[s];
		return;
	}
	int m=(t+s)/2;
	build_tree(s,m,p*2);
	build_tree(m+1,t,p*2+1);
	tree[p]=max(tree[p*2],tree[p*2+1]);
}

void update_tree(int l,int r,int c,int s=1,int t=n,int p=1){
	if (l<=s&&t<=r){
		tree[p]+=c;
		lazy[p]+=c;
		return;
	}
	int m=(t+s)/2;
	if (lazy[p]&&s!=t){
		tree[p*2]+=lazy[p],tree[p*2+1]+=lazy[p];
		lazy[p*2]+=lazy[p];
		lazy[p*2+1]+=lazy[p];
		lazy[p]=0;
	}
	if (l<=m) update_tree(l,r,c,s,m,p*2);
	if (r>m) update_tree(l,r,c,m+1,t,p*2+1);
	tree[p]=max(tree[p*2],tree[p*2+1]);
}

int get_max(int l,int r,int s=1,int t=n,int p=1){
	if (l<=s&&t<=r) return tree[p];
	int m=(t+s)/2;
	int max_num=0;
	if (lazy[p]){
		tree[p*2]+=lazy[p],tree[p*2+1]+=lazy[p];
		lazy[p*2]+=lazy[p];
		lazy[p*2+1]+=lazy[p];
		lazy[p]=0;
	}
	if (l<=m) max_num=get_max(l,r,s,m,p*2);
	if (r>m) max_num=max(max_num,get_max(l,r,m+1,t,p*2+1));
	return max_num;
}

int main(){
	int m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>input[i];
	}
	build_tree();
	for (int i=0;i<m;i++){
		int a;
		cin>>a;
		int z=0;
		for (int j=n;j>=1;j/=2){
			if (z+j>n) continue;
			while (z+j<=n&&get_max(1,z+j)<a) z+=j;
		}
		if (z<n){
			z++;
			update_tree(z,z,-a);
			cout<<z<<" ";
		} else cout<<0<<" ";
	}
}