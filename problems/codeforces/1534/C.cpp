// created on 2021/6/14 by spacefarers
// problem: C. Little Alawn's Puzzle

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int nums[400005][2],track[400005][2];
ll ans=1,MOD=1e9+7;
bool visited[400005];

void dfs(int col,bool first=true){
    if (visited[col]) return;
    visited[col]=true;
    if (first){
        ans*=2;
        ans%=MOD;
    }
    dfs(track[nums[col][1]][0],false);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(visited,false,sizeof visited);
        ans=1;
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            int a;
            cin>>a;
            nums[i][0]=a;
            track[a][0]=i;
        }
        for (int i=1;i<=n;i++){
            int a;
            cin>>a;
            nums[i][1]=a;
            track[a][1]=i;
        }
        for (int i=1;i<=n;i++){
            dfs(i);
        }
        cout<<ans<<endl;
    }
}