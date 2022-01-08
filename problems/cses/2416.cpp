//
// Created by michaelyang on 3:26 PM Jan 07 2022.
// Problem: Increasing Array Queries
// 8/10

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
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

int n,prog;
ll tree[N],pre[N],a[N];

void add(ll k,ll x){
	while (k<=n){
		tree[k]+=x;
		k+=k&-k;
	}
}

ll get_sum(ll k){
	ll ans=0;
	while (k>0){
		ans+=tree[k];
		k-=k&-k;
	}
	return ans;
}

deque<int> st;

void moveLeft(){
	prog--;
	while (!st.empty()&&a[st.front()]<a[prog]){
		add(st.front(),-(get_sum(st.front())-get_sum(st.front()-1)));
		st.pop_front();
	}
	int r=n+1;
	if (!st.empty()){
		r=st.front();
	}
	st.push_front(prog);
	add(prog,(r-prog)*a[prog]-(pre[r-1]-pre[prog-1]));
}

int main(){
	fastio
	int q;
	cin>>n>>q;
	prog=n+1;
	for (int i=1;i<=n;i++){
		ll x;
		cin>>x;
		a[i]=x;
		pre[i]=x+pre[i-1];
	}
	vector<pair<pair<int,int>,pair<int,ll>>> ranges;
	for (int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		ranges.push_back({{x,y},{i,0}});
	}
	sort(ranges.begin(),ranges.end(),greater<>());
	for (auto &i:ranges){
		while (i.f.f<prog) moveLeft();
		auto it=prev(upper_bound(st.begin(),st.end(),i.f.s));
		int lastPart=i.f.s-*it+1;
		ll ans=lastPart*a[*it]-(pre[i.f.s]-pre[*it-1]);
		ans+=get_sum(*it-1);
		i.s.s=ans;
	}
	sort(ranges.begin(),ranges.end(),[](auto a,auto b){
		return a.s.f<b.s.f;
	});
	for (auto &i:ranges){
		cout<<i.s.s<<endl;
	}
}