#include <iostream>
#include <vector>

using namespace std;

#define MAXN 500005

bool visited[MAXN];
int father[MAXN],ans[MAXN];
vector<int> graph[MAXN];
vector<pair<int,int>> query[MAXN];

int find(int x){
    if (father[x]!=x) return find(father[x]);
    return x;
}


void dfs(int v){
    visited[v]=true;
    father[v]=v;
    for (auto i:graph[v]){
        if (!visited[i]){
            dfs(i);
            father[i]=v;
        }
    }
    for (auto i:query[v]){
        if (visited[i.second]){
            ans[i.first]=find(i.second);
        }
    }
}

int main(){
    // Tarjan LCA template
    int n,m,s;
    cin>>n>>m>>s;
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        query[a].emplace_back(i,b);
        query[b].emplace_back(i,a);
    }
    dfs(s);
    for (int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
}