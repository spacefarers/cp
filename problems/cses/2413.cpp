// created on 2021/6/29 by spacefarers
// problem: DP: Counting Towers

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll dp[1000005][2],MOD=1e9+7; // split or no split

int main(){
    int t,i=1;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        dp[0][0]=1;
        dp[0][1]=1;
        for (;i<n;i++){
            dp[i][0]=dp[i-1][0]*4+dp[i-1][1];
            dp[i][1]=dp[i-1][0]+dp[i-1][1]*2;
            dp[i][0]%=MOD;
            dp[i][1]%=MOD;
        }
        cout<<(dp[n-1][0]+dp[n-1][1])%MOD<<endl;
    }
}