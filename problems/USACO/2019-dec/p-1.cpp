// created on 2021/7/8 by spacefarers
// problem: Problem 1. Greedy Pie Eaters

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int dp[305][305],hit[305][305][305];

void setIO(const string&name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    setIO("pieaters");
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        for (int j=b;j<=c;j++){
            hit[j][b][c]=a;
        }
    }
    for (int j=n;j>=1;j--){
        for (int k=j;k<=n;k++){
            for (int i=j;i<=k;i++){
                hit[i][j][k]=max(hit[i][j][k],hit[i][j+1][k]);
                hit[i][j][k]=max(hit[i][j][k],hit[i][j][k-1]);
            }
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=i;j<=n;j++){
            for (int k=i;k<=j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                dp[i][j]=max(dp[i][j],dp[i][k-1]+hit[k][i][j]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
}