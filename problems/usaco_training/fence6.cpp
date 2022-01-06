/*
ID: michael419
LANG: C++
TASK: fence6
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

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int p[210], lengths[210];
vector<pair<int, int>> paths[210];

struct node{
	vector<int> p;
	void read(int k, int n){
		p.push_back(k);
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			p.push_back(a);
		}
		sort(p.begin(), p.end());
	}
	bool check(const node& x){
		for (int i=0;i<p.size();i++){
			if (p[i]!=x.p[i]) return false;
		}
		return true;
	}
} fences[205];

int ans=0x7fffffff;
bool vis[210];

void dfs(int x, int prev, int dep){
	if (vis[x]){
		ans=min(ans, dep);
		return;
	}
	vis[x]=true;
	for (auto &i:paths[x]){
		if (i.first==prev) continue;
		dfs(i.first, x, dep+i.second);
	}
	vis[x]=false;
}

int main(){
	setIO("fence6");
	int N;
	cin>>N;
	for (int i=0;i<N;i++){
		int s, n1, n2;
		cin>>s>>lengths[i]>>n1>>n2;
		fences[i*2].read(s, n1);
		fences[i*2+1].read(s, n2);
	}
	memset(p, -1, sizeof p);
	N*=2;
	for (int i=0;i<N;i++){
		if (p[i]==-1){
			p[i]=i;
			for (int j=i+1;j<N;j++){
				if (p[j]==-1&&fences[i].check(fences[j])) p[j]=p[i];
			}
		}
	}
	for (int i=0;i<N/2;i++){
		int a=p[i*2], b=p[i*2+1];
		paths[a].emplace_back(b, lengths[i]);
		paths[b].emplace_back(a, lengths[i]);
	}
	for (int i=0;i<N;i++){
		dfs(i, -1, 0);
	}
	cout<<ans<<endl;
}