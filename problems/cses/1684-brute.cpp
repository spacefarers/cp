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

vector<int> toppings[N][2];
pair<bool,int> decisions[N][2];
int res[N];

bool satisfy(int x){
	for (int i=0;i<2;i++){
		auto [like,top]=decisions[x][i];
		if ((res[top]==-1&&!like)||(res[top]==1&&like)) return true;
	}
	return false;
}

int n,m;

void solve(int x){
	if (x==n+1){
		for (int i=1;i<=m;i++){
			if (res[i]==-1) cout<<"- ";
			else cout<<"+ ";
		}
		exit(0);
	}
	if (satisfy(x)) solve(x+1);
	for (int i=0;i<2;i++){
		auto [like,top]=decisions[x][i];
		if (res[top]!=0) continue;
		if (like) res[top]=1;
		else res[top]=-1;
		solve(x+1);
		res[top]=0;
	}
}

int main(){
	fastio
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=0;j<2;j++){
			char x;
			int y;
			cin>>x>>y;
			int like=0;
			if (x=='+') like=1;
			toppings[y][like].push_back(i);
			decisions[i][j]={like,y};
		}
	}
	solve(1);
	cout<<"IMPOSSIBLE"<<endl;
}