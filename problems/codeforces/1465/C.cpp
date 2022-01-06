// created on 6/20/21 by spacefarers
// problem: C. Peaceful Rooks

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int path[100005];
bool vis[100005];
int ans;

void dfs(int x,int source){
    if (vis[x]) return;
    vis[x]=true;
    if (x==source){
        if (path[x]==source) ans--;
        else ans++;
    }
    dfs(path[x],source);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        ans=m;
        memset(path,0,sizeof path);
        memset(vis,false,sizeof vis);
        for (int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            path[x]=y;
        }
        for (int i=1;i<=n;i++){
            dfs(path[i],i);
        }
        cout<<ans<<endl;
    }
}