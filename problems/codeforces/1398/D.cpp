// created on 2021/7/6 by spacefarers
// problem: D. Colored Rectangles

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int dp[205][205][205];
int len[3][205];

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    for (int i=1;i<=r;i++){
        cin>>len[0][i+1];
    }
    for (int i=1;i<=g;i++){
        cin>>len[1][i+1];
    }
    for (int i=1;i<=b;i++){
        cin>>len[2][i+1];
    }
    sort(len[0]+2,len[0]+r+2,greater<>());
    sort(len[1]+2,len[1]+g+2,greater<>());
    sort(len[2]+2,len[2]+b+2,greater<>());
    int ans=0;
    for (int i=1;i<=r+1;i++){
        for (int j=1;j<=g+1;j++){
            for (int k=1;k<=b+1;k++){
                int ans1=1e9,ans2=1e9,ans3=1e9;
                ans1=dp[i-1][j-1][k]+len[0][i]*len[1][j];
                ans2=dp[i][j-1][k-1]+len[1][j]*len[2][k];
                ans3=dp[i-1][j][k-1]+len[0][i]*len[2][k];
                dp[i][j][k]=max(max(ans1,max(ans2,ans3)),dp[i-1][j-1][k-1]);
                ans=max(ans,dp[i][j][k]);
            }
        }
    }
    cout<<ans<<endl;
}