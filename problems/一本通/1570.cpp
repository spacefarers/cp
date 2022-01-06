// created on 2021/6/21 by spacefarers
// problem: 1570：【例 2】能量项链

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

pair<int,int> pearl[205];
int dp[205][205];

int main(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for (int i=1;i<=n;i++){
        cin>>nums[i];
    }
    for (int i=1;i<=n;i++){
        pearl[i].f=pearl[i+n].f=nums[i];
        if (i==n) pearl[i].s=pearl[i+n].s=nums[1];
        else pearl[i].s=pearl[i+n].s=nums[i+1];
    }
    for (int i=2*n;i>0;i--){
        for (int j=i+1;j<=2*n;j++){
            for (int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+pearl[i].f*pearl[k].s*pearl[j].s);
            }
        }
    }
    int ans=0;
    for (int i=1;i<=2*n;i++){
        ans=max(ans,dp[i][i+n-1]);
    }
    cout<<ans<<endl;
}