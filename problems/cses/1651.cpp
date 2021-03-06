// created on 2021/7/10 by spacefarers
// problem: Range Update Queries
// Sum Segment Tree Template
// 和线段树模板

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

const int MOD=1e9+7;
const int N=2e5+5;

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
	update_tree(l,r,c,v*2+1,m+1,tr);
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
    int q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>inputs[i];
    }
    build_tree();
    for (int i=0;i<q;i++){
        int a;
        cin>>a;
        if (a==1){
            int b,c,d;
            cin>>b>>c>>d;
            update_tree(b,c,d);
        } else {
            int b;
            cin>>b;
            cout<<get_sum(b,b)<<endl;
        }
    }
}