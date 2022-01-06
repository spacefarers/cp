/*
ID: michael419
LANG: C++
TASK: telecow
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
#include <unordered_map>
#include <fstream>

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

const int maxn=1e3+10;
const int maxm=4e4+100;
const int inf=1e9;



int n,m;
struct Dinic {
	int dis[maxn],cur[maxn];
	struct Edge {
		int u,v,w,nxt;
	} e[maxm],ee[maxm];
	inline void add(int u,int v,int w){
		e[++cnt].v=v;
		e[cnt].u=u;
		e[cnt].w=w;
		e[cnt].nxt=first[u];
		first[u]=cnt;
	}
	int first[maxn]={},cnt=1,S,T;
	int bfs(int s,int t){
		memset(dis,-1,sizeof(dis));
		queue<int> q;
		dis[s]=0;
		q.push(s);
		while (!q.empty()){
			int u=q.front();
			q.pop();
			for (int i=first[u];i;i=e[i].nxt){
				int v=e[i].v;
				if (dis[v]!=-1||e[i].w==0)continue;
				dis[v]=dis[u]+1;
				q.push(v);
				if (v==t)return 1;
			}
		}
		return 0;
	}

	int dfs(int u,int t,int f){
		if (!f||u==t) return f;
		int w,used=0;
		for (int &i=cur[u];i;i=e[i].nxt){
			int v=e[i].v;
			if (dis[v]!=dis[u]+1||e[i].w==0)continue;
			w=dfs(v,t,min(f,e[i].w));
			used+=w;
			f-=w;
			e[i].w-=w;
			e[i^1].w+=w;
			if (f==0)break;
		}
		return used;
	}

	int dinic(int s,int t){
		int ret=0;
		while (bfs(s,t)){
			memcpy(cur,first,sizeof(first));
			ret+=dfs(s,t,inf);
		}
		return ret;
	}
};

int main(){
	setIO("telecow");
	int S, T;
	cin>>n>>m>>S>>T;
	auto graph=Dinic{};
	for (int i=1;i<=n;i++){
		graph.add(i,i+n,1);//拆点
		graph.add(i+n,i,0);//拆点
	}
	for (int i=1;i<=m;i++){
		int u, v;
		cin>>u>>v;
		graph.add(u+n,v,inf);
		graph.add(v,u+n,0);
		graph.add(v+n,u,inf);
		graph.add(u,v+n,0);
	}
	memcpy(graph.ee,graph.e,sizeof(graph.e));
	S+=n;
	int ans=graph.dinic(S, T);
	cout<<ans<<endl;
	bool firstoff=true;
	for (int i=2;i<=2*n;i+=2){
		graph.ee[i].w=0;
		memcpy(graph.e,graph.ee,sizeof(graph.e));
		int tmp=graph.dinic(S,T);
		if (tmp==ans) //如果最大流没有改变，则不是割边
			graph.ee[i].w=1;
		else
			if (firstoff) {
				cout<<i/2;
				firstoff=false;
			}
			else cout<<" "<<i/2;
			ans=tmp;//最大流改变，这条边就是在割集中
	}
	cout<<endl;
}