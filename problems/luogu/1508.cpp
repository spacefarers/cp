#include <iostream>
#include <cstring>

using namespace std;

int dp[205][205];

int main(){
    int m,n;
    cin>>m>>n;
    memset(dp,-0x3f,sizeof dp);
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin>>dp[i][j];
        }
    }
    dp[m+1][n/2+1]=0;
    for (int i=m;i>0;i--){
        for (int j=1;j<=n;j++){
            dp[i][j]+=max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1]);
//            if (dp[i][j]<0) dp[i][j]=-1e8;
        }
    }
    int max_item=0;
    for (auto i:dp[1]){
        max_item=max(max_item,i);
    }
     cout<<max_item<<endl;
}