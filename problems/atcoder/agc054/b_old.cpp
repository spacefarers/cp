// created on 2021/6/27 by spacefarers
// problem: B - Greedy Division

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll MOD=998244353;
vector<ll> dp[10005];

int main(){
    int n;
    cin>>n;
    vector<int> ops;
    int acc=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        ops.push_back(a);
        acc+=a;
    }
    acc/=2;
    dp[0].push_back(0);
    for (auto j:ops){
        for (int i=acc;i>=0;i--){
            if (i-j>=0){
                for (auto k:dp[i-j]){
                    dp[i].push_back(k+1);
                }
            }
        }
    }
    ll ans=0;
    for (auto i:dp[acc]){
        ll c_ans=1;
        for (int j=1;j<=i;j++){
            c_ans*=j;
            c_ans%=MOD;
        }
        for (int j=1;j<=n-i;j++){
            c_ans*=j;
            c_ans%=MOD;
        }
        ans+=c_ans;
        ans%=MOD;
    }
    cout<<ans<<endl;
}