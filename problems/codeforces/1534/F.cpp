// created on 2021/6/14 by spacefarers
// problem: F. Falling Sand
// idea: use kosaraju's algo for solving strongly connected components

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <stack>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

string board[400005];
int n,m,parent[400005],deg[400005];
vector<vector<bool>> vis;
vector<vector<int>> ind;

vector<int> adj[400005];
int tarj_id[400005],lowlink[400005],id_count=1;
bool instack[400005];
vector<int> st;
vector<vector<int>> components;

void tarjan(int loc){
    tarj_id[loc]=lowlink[loc]=id_count++;
    instack[loc]=true,st.push_back(loc);
    for (auto i:adj[loc]){
        if (!tarj_id[i]) tarjan(i),lowlink[loc]=min(lowlink[loc],lowlink[i]);
        else if (instack[i]) lowlink[loc]=min(lowlink[loc],lowlink[i]);
    }
    if (tarj_id[loc]==lowlink[loc]){
        vector<int> comp;
        while (true){
            int u=st.back();
            st.pop_back();
            comp.push_back(u);
            parent[u]=(int)components.size();
            instack[u]=false;
            if (u==loc) break;
        }
        components.push_back(comp);
    }
}

int main(){
    cin>>n>>m;
    vis.resize(n);
    ind.resize(n);
    for (int i=0;i<n;i++){
        vis[i].resize(m);
        ind[i].resize(m);
        cin>>board[i];
    }
    int node_id=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (board[i][j]=='#') ind[i][j]=node_id++;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!ind[i][j]) continue;
            if (i-1>=0&&ind[i-1][j]) adj[ind[i][j]].push_back(ind[i-1][j]);
            for (int k=i+1;k<n;k++){
                if (ind[k][j]){
                    adj[ind[i][j]].push_back(ind[k][j]);
                    break;
                }
            }
            if (j-1>=0){
                for (int k=i;k<n&&(!ind[k][j]||i==k);k++){ // key optimization you can skip if the middle is valid
                    if (ind[k][j-1]){
                        adj[ind[i][j]].push_back(ind[k][j-1]);
                        break;
                    }
                }
            }
            if (j+1<m){
                for (int k=i;k<n&&(!ind[k][j]||i==k);k++){
                    if (ind[k][j+1]){
                        adj[ind[i][j]].push_back(ind[k][j+1]);
                        break;
                    }
                }
            }
        }
    }
    for (int i=1;i<node_id;i++){
        if (!tarj_id[i]) tarjan(i);
    }
    for (auto&i:components){
        for (auto j:i){
            for (auto k:adj[j]){
                if (parent[j]!=parent[k]) deg[parent[k]]++;
            }
        }
    }
    int ans=0;
    for (int i=0;i<components.size();i++){
        if (deg[i]==0) ans++;
    }
    cout<<ans<<endl;
}