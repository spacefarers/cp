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
ll dp[10005][105];

int main(){
    ll n;
    cin>>n;
    vector<ll> ops;
    ll acc=0;
    for (ll i=0;i<n;i++){
        ll a;
        cin>>a;
        ops.push_back(a);
        acc+=a;
    }
    if (acc%2){
        cout<<0<<endl;
        return 0;
    }
    acc/=2;
    dp[0][0]=1;
    sort(ops.begin(),ops.end(),greater<>());
    for (auto j:ops){
        for (ll i=acc;i>=j;i--){
            for (ll k=1;k<=n;k++){
                dp[i][k]+=dp[i-j][k-1];
                dp[i][k]%=MOD;
            }
        }
    }
    ll ans=0;
    for (ll i=1;i<=n;i++){
        ll x=dp[acc][i];
        ll c_ans=1;
        for (ll j=1;j<=i;j++){
            c_ans*=j;
            c_ans%=MOD;
        }
        for (ll j=1;j<=n-i;j++){
            c_ans*=j;
            c_ans%=MOD;
        }
        ans+=(c_ans*x)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}