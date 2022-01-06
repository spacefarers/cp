// created on 2021/6/26 by spacefarers
// problem: E - Mod i

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll dp[3005][3005],prefix[3005],mem[3005][3005];
ll nums[3005],MOD=1e9+7;

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>nums[i];
        prefix[i]=nums[i]+prefix[i-1];
    }
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            for (int k=1;k<=i;k++){
                if ((prefix[i]-prefix[k-1])%j==0)
                    dp[i][j]+=dp[k-1][j-1];
                dp[i][j]%=MOD;
            }
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=dp[n][i];
        ans%=MOD;
    }
    cout<<ans<<endl;
}