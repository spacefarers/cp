#include <iostream>

using namespace std;

#define ll long long

ll mod=1e9+7;

ll modpow(ll x, ll n){
    if (n==0) return 1%mod;
    long long u=modpow(x, n/2);
    u=(u*u)%mod;
    if (n%2) u=(u*x)%mod;
    return u;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        mod--;
        ll y=modpow(b, c);
        mod++;
        cout<<modpow(a, y)<<endl;
    }
}