// created on 2021/6/17 by spacefarers
// problem: #10155. 「一本通 5.2 例 3」数字转换

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

vector<int> paths[50005];
int dp[50005][2]; //最长和次长
bool vis[50005];

int factor_sum(int x){
    int ans=0;
    for (int i=1;i*i<=x;i++){
        if (x%i==0){
            if (i*i==x) ans+=i;
            else ans+=i,ans+=x/i;
        }
    }
    return ans;
}

void solve(int p){
    if (dp[p][0]!=-1) return;
    vis[p]=true;
    for (auto i:paths[p]){
        if (!vis[i]) solve(i);
        if (dp[])
    }
    vis[p]=false;
}

int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u=factor_sum(i);
        if (u<i){
            paths[i].push_back(u);
            paths[u].push_back(i);
        }
    }
    memset(dp,-1,sizeof dp);
}