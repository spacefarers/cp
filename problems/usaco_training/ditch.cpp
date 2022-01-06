/*
ID: michael419
LANG: C++
TASK: ditch
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

ll paths[205][205];
ll parent[205];
ll n, m, s, t;

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
	setIO("ditch");
	cin>>m>>n;
	s=0, t=n-1;
	for (int i=0;i<m;i++){
		ll a, b, c;
		cin>>a>>b>>c;
		a--;b--;
		paths[a][b]+=c;
	}
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