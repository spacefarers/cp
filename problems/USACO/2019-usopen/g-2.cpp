//
// Created by michaelyang on 4:49 PM Dec 31 2021.
// Problem: USACO 2019 US Open Contest, Gold
// Problem 2. I Would Walk 500 Miles

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

const ll MOD=2019201997;
const int N=7505;

int father[N];

ll getCost(ll a,ll b){
	if (a>b) swap(a,b);
	return (2019201913*a+2019201949*b)%MOD;
}

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a,int b){
	int c=find(a),d=find(b);
	father[c]=d;
}

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	setIO("walk");
	int n,k;
	cin>>n>>k;
	vector<pair<ll,pair<int,int>>> cowCost;
	for (int i=1;i<=n;i++){
		father[i]=i;
		ll minItem=1e12;
		int il,jl;
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (getCost(i,j)<minItem){
				minItem=getCost(i,j);
				il=i;
				jl=j;
			}
		}
		cowCost.push_back({minItem,{il,jl}});
	}
	sort(cowCost.begin(),cowCost.end());
	for (auto &i:cowCost){
		if (find(i.s.f)!=find(i.s.s)){
			if (k==n){
				cout<<i.f<<endl;
				return 0;
			}
			if (find(i.s.f)==i.s.f||find(i.s.s)==i.s.s){
				if (find(i.s.f)==i.s.f&&find(i.s.s)==i.s.s){
					k--;
					n-=2;
				} else n--;
				unionn(i.s.f,i.s.s);
			} else {
				cout<<i.f<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
}