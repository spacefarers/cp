// created on 2021/6/16 by spacefarers
// problem: #10157. 「一本通 5.2 例 5」皇宫看守

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int dp[1505][3],cost[1505]; // 0：自己亮上下无所谓，1：自己不亮上面亮，2：自己不亮上面不亮下面至少亮一个
vector<int> paths[1505];

void solve(int p,int par){
    if (dp[p][0]!=-1&&dp[p][1]!=-1) return;
    dp[p][0]=cost[p];
    dp[p][1]=0;
    dp[p][2]=0;
    int diff=1e9;
    for (auto i:paths[p]){
        if (i==par) continue;
        solve(i,p);
        dp[p][0]+=min(dp[i][0],min(dp[i][1],dp[i][2]));
        dp[p][1]+=min(dp[i][0],dp[i][2]);
        dp[p][2]+=min(dp[i][0],dp[i][2]);
        diff=min(diff,dp[i][0]-min(dp[i][0],dp[i][2]));
    }
    dp[p][2]+=diff;
}

int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for (int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        cost[a]=b;
        for (int j=0;j<c;j++){
            int d;
            cin>>d;
            paths[d].push_back(a);
            paths[a].push_back(d);
        }
    }
    solve(1,-1);
    cout<<min(dp[1][0],dp[1][2])<<endl;
}