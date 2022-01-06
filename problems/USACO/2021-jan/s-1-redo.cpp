#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int cows[100005], ans[100005];
bool used[100005], vis[100005];
vector<int> been_to[100005], connected;
int c_ans=0;

void dfs(int x){
    if (vis[x]) return;
    connected.push_back(x);
    vis[x]=true;
    for (auto &i:been_to[x]){
        if (!used[i]) {
            c_ans++;
            used[i]=true;
        }
    }
    dfs(cows[x]);
}

int main(){
    int n, k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cows[i]=i;
        been_to[i].push_back(i);
    }
    for (int i=0;i<k;i++){
        int a, b;
        cin>>a>>b;
        been_to[cows[a]].push_back(b);
        been_to[cows[b]].push_back(a);
        swap(cows[a], cows[b]);
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            memset(used, false, sizeof used);
            connected.clear();
            c_ans=0;
            dfs(i);
            for (auto &j:connected){
                ans[j]=c_ans;
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}