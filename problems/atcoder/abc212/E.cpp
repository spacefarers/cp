// created on 2021/7/31 by spacefarers
// problem: E - Safety Journey

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

vector<int> unusableRoads[5005];
ll dp[5005][5005],MOD=998244353;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        unusableRoads[u].push_back(v);
        unusableRoads[v].push_back(u);
    }
    dp[0][1]=1;
    ll lastLayer=1;
    for (int j=1;j<=k;j++){
        for (int i=1;i<=n;i++){
            dp[j][i]=lastLayer-dp[j-1][i];
            for (auto l:unusableRoads[i]){
                dp[j][i]-=dp[j-1][l];
            }
            dp[j][i]=(dp[j][i]%MOD+MOD)%MOD;
        }
        lastLayer=0;
        for (int i=1;i<=n;i++){
            lastLayer+=dp[j][i];
        }
        lastLayer%=MOD;
    }
    cout<<dp[k][1]<<endl;
}