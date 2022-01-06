#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 100005

vector<int> graph[MAXN];
vector<pair<int,pair<int,int>>> query[MAXN];
int type[MAXN],child[MAXN],ans[MAXN];

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int v,int parent){
    int bp=child[type[v]];
    for (auto i:query[v]){
        if (ans[i.second.first]==-1)
            ans[i.second.first]=child[i.second.second];
        else
            ans[i.second.first]=ans[i.second.first]!=child[i.second.second];
    }
    for (auto i:graph[v]){
        if (i==parent) continue;
        child[type[v]]=i;
        dfs(i,v);
    }
    child[type[v]]=bp;
}

int main() {
    setIO("milkvisits");
    int n, m;
    cin>>n>>m;
    memset(ans,-1,sizeof ans);
    for (int i=1;i<=n;i++){
        cin>>type[i];
    }
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if (type[a]==c||type[b]==c) ans[i]=1;
        query[a].push_back({b,{i,c}});
        query[b].push_back({a,{i,c}});
    }
    dfs(1,-1);
    for (int i=0;i<m;i++){
        cout<<ans[i];
    }
}

