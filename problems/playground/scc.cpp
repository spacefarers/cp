#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int n, m, who[100005];
vector<int> paths[100005], rev_path[100005];
bool vis[100005];
stack<int> order;

void dfs1(int x){
    if (vis[x]) return;
    vis[x]=true;
    for (auto &i:paths[x]) dfs1(i);
    order.push(x);
}

void dfs2(int source, int x){
    if (vis[x]) return;
    vis[x]=true;
    cout<<x<<" ";
    who[x]=source;
    for (auto &i:rev_path[x]) dfs2(source, i);
}

int main(){
    cin>>n>>m;
    for (int i=0;i<m;++i){
        int a, b; // path from a to b
        cin>>a>>b;
//        a--;b--; // if 1 indexed, like most problems
        paths[a].push_back(b);
        rev_path[b].push_back(a);
    }
    for (int i=0;i<n;++i){
        if (!vis[i]) dfs1(i);
    }
    // we will just use the reversed graph that we built on input, this is not the most optimal space
    memset(vis, false, sizeof vis);
    while (!order.empty()){
        int u=order.top();
        order.pop();
        if (!vis[u]) {
            dfs2(u, u);
            cout<<endl;
        }
    }
    return 0;
}