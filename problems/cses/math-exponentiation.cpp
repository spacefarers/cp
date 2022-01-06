#include <iostream>

using namespace std;

int mod=1e9+7;

long long modpow(int x, int n){
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
        int a, b;
        cin>>a>>b;
        cout<<modpow(a, b)<<endl;
    }
}