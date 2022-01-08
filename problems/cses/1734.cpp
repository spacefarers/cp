//
// Created by michaelyang on 1:13 AM Jan 07 2022.
// Problem: Distinct Values Queries

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
int prog=1;


int c[N],n,lastI[N],nextI[N];

void add(int k, int x){
	while (k<=n){
		c[k]+=x;
		k+=k&(-k);
	}
}

int get_sum(int k){
	int ans=0;
	while (k>0){
		ans+=c[k];
		k-=k&(-k);
	}
	return ans;
}

void moveLeft(){
	if (prog>n) return;
	if (nextI[prog]!=-1) add(nextI[prog],1);
	add(prog,-1);
	prog++;
}

int main(){
	fastio
	memset(lastI,-1,sizeof lastI);
	memset(nextI,-1,sizeof nextI);
	int q;
	cin>>n>>q;
	map<int,int> mp;
	for (int i=1;i<=n;i++){
		int a;
		cin>>a;
		if (mp.find(a)!=mp.end()){
			lastI[i]=mp[a];
			nextI[mp[a]]=i;
		}
		mp[a]=i;
	}
	for (int i=1;i<=n;i++){
		if (lastI[i]==-1) add(i,1);
	}
	vector<pair<pair<int,int>,pair<int,int>>> ranges;
	for (int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		ranges.push_back({{a,b},{i,0}});
	}
	sort(ranges.begin(),ranges.end());
	for (auto &i:ranges){
		while (prog<i.f.f) moveLeft();
		i.s.s=get_sum(i.f.s);
	}
	sort(ranges.begin(),ranges.end(),[](pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b){
		return a.s.f<b.s.f;
	});
	for (auto &i:ranges){
		cout<<i.s.s<<endl;
	}
}