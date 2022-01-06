/*
ID: michael419
LANG: C++
TASK: schlnet
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

int who[105];
vector<int> paths[105], rev_path[105];
bool vis[105];
stack<int> order;
int in_deg[105], out_deg[105];

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void dfs1(int x){
	if (vis[x]) return;
	vis[x]=true;
	for (auto &i:paths[x]) dfs1(i);
	order.push(x);
}

void dfs2(int source, int x){
	if (vis[x]) return;
	vis[x]=true;
	who[x]=source;
	for (auto &i:rev_path[x]) dfs2(source, i);
}

int main(){
	setIO("schlnet");
	int N;
	cin>>N;
	for (int i=0;i<N;i++){
		int x;
		while (cin>>x&&x!=0){
			paths[i].push_back(x-1);
			rev_path[x-1].push_back(i);
		}
	}
	for (int i=0;i<N;i++){
		if (!vis[i]) dfs1(i);
	}
	memset(vis, false, sizeof vis);
	while (!order.empty()){
		int u=order.top();
		order.pop();
		if (!vis[u]){
			dfs2(u, u);
		}
	}
	bool one_point=true;
	for (int i=0;i<N;i++){
		if (who[i]!=who[i+1]) one_point=false;
		for (auto &j:paths[i]){
			if (who[i]==who[j]) continue;
			out_deg[who[i]]++;
			in_deg[who[j]]++;
		}
	}
	set<int> in_zero, out_zero;
	for (int i=0;i<N;i++){
		if (in_deg[who[i]]==0) in_zero.insert(who[i]);
		if (out_deg[who[i]]==0) out_zero.insert(who[i]);
	}
	cout<<in_zero.size()<<endl;
	if (!one_point)
		cout<<max(in_zero.size(), out_zero.size())<<endl;
	else cout<<0<<endl;
}