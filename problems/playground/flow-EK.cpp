#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define f first
#define s second

int paths[5005][5005];
int parent[5005];
int n, m, s, t;

int bfs(){
    memset(parent, -1, sizeof parent);
    parent[s]=-2;
    queue<pair<int, int>> q;
    q.push({s, 0x7fffffff});
    while (!q.empty()){
        auto u=q.front();
        q.pop();
        for (int i=0;i<n;i++){
            if (parent[i]==-1&&paths[u.f][i]){
                parent[i]=u.f;
                int new_flow=min(u.s, paths[u.f][i]);
                if (i==t) return new_flow;
                q.push({i, new_flow});
            }
        }
    }
    return 0;
}

int main(){
    cin>>n>>m>>s>>t;
    s--;t--;
    for (int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--;b--;
        paths[a][b]+=c;
    }
    int flow=0, new_flow;
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
    cout<<flow<<endl;
}