//
// Created by michaelyang on 11:19 PM Jan 01 2022.
// Problem: Road Reparation

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

int father[N];

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a,int b){
	int c=find(a),d=find(b);
	father[c]=d;
}

int main(){
	fastio
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		father[i]=i;
	}
	vector<pair<int,pair<int,int>>> paths;
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths.push_back({c,{a,b}});
	}
	sort(paths.begin(),paths.end());
	ll ans=0;
	for (auto &i:paths){
		if (find(i.s.f)!=find(i.s.s)){
			unionn(i.s.f,i.s.s);
			ans+=i.f;
		}
	}
	for (int i=2;i<=n;i++){
		if (find(i)!=find(1)){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
}