#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> paths[200005];
int dep[200005], max_1=0, min_1=0x7fffffff, val[200005], stage[200005][2];

void solve1(int x, int c_val){
    bool ok=true;
    for (auto &i:paths[x]){
        if (dep[i]>=dep[x]) continue;
        ok=false;
        solve1(i, c_val+val[x]);
    }
    if (!ok) {
        max_1=max(max_1, c_val+val[x]);
        min_1=min(min_1, c_val+val[x]);
    }
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            int a;
            cin>>a;
            a--;
            paths[a].push_back(i);
            paths[i].push_back(a);
        }
        for (int i=1;i<=n;i++) cin>>val[i];
        memset(dep, -1, sizeof dep);
        dep[0]=0;
        queue<int> q;
        q.push(0);
        int step=1;
        while (!q.empty()){
            int sz=q.size();
            for (int i=0;i<sz;i++){
                auto u=q.front();
                q.pop();
                for (auto &j:paths[u]){
                    if (dep[j]==-1){
                        dep[j]=step;
                        q.push(j);
                    }
                }
            }
            step++;
        }
        solve1(0, 0);
        for (int i=1;i<=n;i++){
            stage[dep[i]][0]=max(val[i], stage[dep[i]][0]);
            stage[dep[i]][1]=min(val[i], stage[dep[i]][1]);
        }
        
    }
}