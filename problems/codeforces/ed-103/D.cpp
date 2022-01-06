#include <iostream>
#include <cstring>

using namespace std;

string directions;
int n, counts[300005], father[300005], ans[300005];
bool vis[300005];

void flood_fill(int x, bool state, int source){
    if (vis[x]) return;
    vis[x]=true;
    father[x]=source;
    counts[source]++;
    if (x>0&&(directions[x-1]=='L')^state) flood_fill(x-1, !state, source);
    if (x<n&&(directions[x]=='R')^state) flood_fill(x+1, !state, source);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n>>directions;
        memset(vis, false, sizeof vis);
        memset(counts, 0, sizeof counts);
        for (int i=0;i<=n;i++) father[i]=i;
        for (int i=0;i<=n;i+=2){
            if (!vis[i]) flood_fill(i, false, i);
        }
        for (int i=0;i<=n;i+=2){
            ans[i]=counts[father[i]];
        }
        for (int i=0;i<=n;i++) father[i]=i;
        memset(vis, false, sizeof vis);
        memset(counts, 0, sizeof counts);
        for (int i=1;i<=n;i+=2){
            if (!vis[i]) flood_fill(i, false, i);
        }
        for (int i=1;i<=n;i+=2){
            ans[i]=counts[father[i]];
        }
        for (int i=0;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}