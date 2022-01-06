//
// Created by michaelyang on 4:44 PM Jan 02 2022.
// Problem: Giant Pizza

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

bool used[N+N];
vector<int> G[N+N],revG[N+N],order;
int who[N+N];

void dfs1(int x){
	if (used[x]) return;
	used[x]=true;
	for (auto &i:G[x]){
		dfs1(i);
	}
	order.push_back(x);
}

void dfs2(int from,int x){
	if (used[x]) return;
	used[x]=true;
	who[x]=from;
	for (auto &i:revG[x]){
		dfs2(from,i);
	}
}

int main(){
	fastio
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		char x1,x2;
		int y1,y2;
		cin>>x1>>y1>>x2>>y2;
		bool x3=false,x4=false;
		if (x1=='+') x3=true;
		if (x2=='+') x4=true;
		int n1=y1,n2=y1+m,n3=y2,n4=y2+m;
		if (!x3) swap(n1,n2);
		if (!x4) swap(n3,n4);
		G[n2].push_back(n3);
		revG[n3].push_back(n2);
		G[n4].push_back(n1);
		revG[n1].push_back(n4);
	}
	for (int i=1;i<=2*m;i++){
		dfs1(i);
	}
	memset(used,false,sizeof used);
	reverse(order.begin(),order.end());
	int c=1;
	for (auto &i:order){
		if (!used[i]) dfs2(c++,i);
	}
	for (int i=1;i<=m;i++){
		if (who[i]==who[i+m]){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<((who[i]>who[i+m])?"+":"-")<<" ";
	}
}