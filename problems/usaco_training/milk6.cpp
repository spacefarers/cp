/*
ID: michael419
LANG: C++
TASK: milk6
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int paths[35][35],backup[35][35];
int parent[35];
int n,m,s,t;

int bfs(){
	memset(parent,-1,sizeof parent);
	parent[s]=-2;
	queue<pair<int,int>> q;
	q.push({s,0x7fffffff});
	while (!q.empty()){
		auto u=q.front();
		q.pop();
		for (int i=0;i<n;i++){
			if (parent[i]==-1&&paths[u.f][i]) {
				parent[i]=u.f;
				int new_flow=min(u.s,paths[u.f][i]);
				if (i==t) return new_flow;
				q.push({i,new_flow});
			}
		}
	}
	return 0;
}

void flush_backup(){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			paths[i][j]=backup[i][j];
		}
	}
}

int edmonds_karp(){
	int flow=0,new_flow;
	while ((new_flow=bfs())){
		flow+=new_flow;
		int c=t;
		while (c!=s){
			int prev=parent[c];
			paths[prev][c]-=new_flow;
			paths[c][prev]+=new_flow;
			c=prev;
		}
	}
	flush_backup();
	return flow;
}

int main(){
	setIO("milk6");
	cin>>n>>m;
	s=0;
	t=n-1;
	vector<pair<pair<int,int>,pair<int,int>>> routes;
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		routes.push_back({{c,i},{a,b}});
		paths[a][b]+=c;
		backup[a][b]+=c;
	}
	int base_val=edmonds_karp();
	sort(routes.begin(),routes.end(),[](pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
		if (a.first.first!=b.first.first) return a.first.first>b.first.first;
		return a.first.second<b.first.second;
	});
	int sum=0;
	vector<int> ans;
	for (auto &route:routes){
		paths[route.s.f][route.s.s]-=route.f.f;
		int new_val=edmonds_karp();
		if (base_val-new_val==route.f.f) {
			ans.push_back(route.f.s);
			sum+=route.f.f;
			if (sum==base_val) break;
		}
	}
	sort(ans.begin(), ans.end());
	cout<<base_val<<" "<<ans.size()<<endl;
	for (auto &i:ans){
		cout<<i+1<<endl;
	}
}