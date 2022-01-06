// created on 2021/7/11 by spacefarers
// problem: D. AquaMoon and Chess

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll MOD=998244353;

ll pow(ll x,ll n){
    if (n==0) return 1%MOD;
    ll u=pow(x,n/2);
    u=(u*u)%MOD;
    if (n%2==1) u=(u*x)%MOD;
    return u;
}

ll inverse(ll n){
    return pow(n,MOD-2);
}

ll NCR(int n,int r){
    if (n<r) return 0;
    if (r==0) return 1;
    ll factorial[n+1];
    factorial[0]=1;
    for (int i=1;i<=n;i++){
        factorial[i]=(factorial[i-1]*i)%MOD;
    }
    return ((factorial[n]*inverse(factorial[r]))%MOD*inverse(factorial[n-r])%MOD)%MOD;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        string x;
        cin>>n>>x;
        int c=0,groups=0,zeros=0;
        for (auto i:x){
            if (i=='1'){
                c++;
            }else{
                groups+=c/2;
                c=0;
                zeros++;
            }
        }
        groups+=c/2;
        cout<<NCR(zeros+groups,groups)<<endl;
    }
}