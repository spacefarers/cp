#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll dp[1000005], mod=1e9+7;

int main() {
    int n, x;
    cin>>n>>x;
    vector<ll> coins(n);
    for (int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=1;
    for (int i=1;i<=x;i++){
	    for (auto &j:coins){
            if (i-j<0) continue;
            dp[i]+=dp[i-j];
        }
        dp[i]%=mod;
    }
    cout<<dp[x]<<endl;
    return 0;
}

