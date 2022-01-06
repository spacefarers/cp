/*
ID: michael419
LANG: C++
TASK: stall4
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define ll long long
#define f first
#define s second

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

ll paths[405][405];
ll parent[405];
int n, m, s, t;

ll bfs(){
	memset(parent, -1, sizeof parent);
	parent[s]=-2;
	queue<pair<ll, ll>> q;
	q.push({s, 1e15});
	while (!q.empty()){
		auto u=q.front();
		q.pop();
		for (int i=0;i<n;i++){
			if (parent[i]==-1&&paths[u.f][i]){
				parent[i]=u.f;
				ll new_flow=min(u.s, paths[u.f][i]);
				if (i==t) return new_flow;
				q.push({i, new_flow});
			}
		}
	}
	return 0;
}

int main(){
	setIO("stall4");
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		for (int j=1;j<=x;j++){
			int a;
			cin>>a;
			paths[i][n+a]=1;
		}
	}
	for (int i=1;i<=n;i++){
		paths[0][i]=1;
	}
	for (int i=n+1;i<=n+m;i++){
		paths[i][n+m+1]=1;
	}
	n=n+m+2;
	s=0, t=n-1;
	ll flow=0, new_flow;
	while ((new_flow=bfs())){
		flow+=new_flow;
		ll c=t;
		while (c!=s){
			ll prev=parent[c];
			paths[prev][c]-=new_flow;
			paths[c][prev]+=new_flow;
			c=prev;
		}
	}
	cout<<flow<<endl;
}