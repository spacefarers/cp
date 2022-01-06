//
// Created by spacefarers on 7:19 PM Nov 28 2021.
// Problem: Prefix Sum Queries

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;


template<class T> struct LSegTree {
	int N{}; vector<T> t, lz; T U=-1e18;
	T F(T i, T j) { return max(i,j); } LSegTree() = default;
	explicit LSegTree(int N) : N(N), t(4*(N+1),U), lz(4*(N+1),0) {}
	void pull(int i) { t[i] = F(t[i*2],t[i*2+1]); }
	void push(int i, int l, int r) {
		t[i]+=lz[i];
		if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
		lz[i]=0; }
	void build(vector<ll> &v) { build(v,1,0,N); }
	void build(vector<ll> &v, int i, int l, int r) {
		if(l==r) { t[i]=v[l]; return; } int m=(l+r)/2;
		build(v,i*2,l,m); build(v,i*2+1,m+1,r); pull(i);
	}
	void upd(int L, int R, T v) { upd(L,R,v,1,0,N); }
	void upd(int L, int R, T v, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return;
		if(L<=l && R>=r) { lz[i]+=v; push(i,l,r); return; }
		int m=(l+r)/2; upd(L,R,v,i*2,l,m);
		upd(L,R,v,i*2+1,m+1,r); pull(i);
	}
	T qry(int L, int R) { return qry(L,R,1,0,N); }
	T qry(int L, int R, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return U;
		if(L<=l && R>=r) return t[i]; int m=(l+r)/2;
		return F(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r));
	}
};

int main(){
	fastio
//	freopen("test.txt","r",stdin);
	int q,n;
	cin>>n>>q;
	LSegTree<ll> st;
	vector<ll> orig(n+1),input(n+1);
	for (int i=1;i<=n;i++){
		cin>>input[i];
		orig[i]=input[i];
		input[i]+=input[i-1];
	}
	st=LSegTree<ll>(n);
	st.build(input);
	for (int i=0;i<q;i++){
		int x;
		cin>>x;
		if (x==1){
			int a;
			ll b;
			cin>>a>>b;
			ll changeVal=b-orig[a];
			orig[a]=b;
			st.upd(a,n,changeVal);
		} else {
			int a,b;
			cin>>a>>b;
			cout<<st.qry(a-1,b)-st.qry(a-1,a-1)<<endl;
		}
	}
}

