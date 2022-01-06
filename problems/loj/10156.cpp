// created on 2021/6/17 by spacefarers
// problem: #10156. 「一本通 5.2 例 4」战略游戏

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

vector<int> paths[1505];
int dp[1505][2]; //0：自己亮下面不需要亮，1：自己不亮下面必须亮

void solve(int p,int par){
    if (dp[p][0]!=-1) return;
    dp[p][0]=1;
    dp[p][1]=0;
    for (auto i:paths[p]){
        if (i==par) continue;
        solve(i,p);
        dp[p][0]+=min(dp[i][0],dp[i][1]);
        dp[p][1]+=dp[i][0];
    }
}

int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        for (int j=0;j<b;j++){
            int c;
            cin>>c;
            paths[c].push_back(a);
            paths[a].push_back(c);
        }
    }
    solve(1,-1);
    cout<<min(dp[1][0],dp[1][1])<<endl;
}