//
// Created by spacefarers on 8:37 PM Nov 24 2021.
// Problem: F. MST Unification

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

int find(int x,vector<int> &father){
	if (father[x]!=x) father[x]=find(father[x],father);
	return father[x];
}

vector<int> changes;

void unionn(int a,int b,vector<int> &father){
	int c=find(a,father),d=find(b,father);
	father[c]=d;
	changes.push_back(c);
}

vector<int> father,lastFather;

int main(){
	fastio
	int n,m;
	cin>>n>>m;
	for (int i=0;i<=n;i++){
		father.push_back(i);
		lastFather.push_back(i);
	}
	vector<pair<int,pair<int,int>>> paths;
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths.push_back({c,{a,b}});
	}
	sort(paths.begin(),paths.end());
	int ans=0,cCost=-1;
	for (auto&i:paths){
		if (cCost!=i.f){
			while (!changes.empty()){
				lastFather[changes.back()]=father[changes.back()];
				changes.pop_back();
			}
			cCost=i.f;
		}
		if (find(i.s.f,father)!=find(i.s.s,father))
			unionn(i.s.f,i.s.s,father);
		else if (find(i.s.f,lastFather)!=find(i.s.s,lastFather))
			ans++;
	}
	cout<<ans<<endl;
}

