// created on 2021/7/3 by spacefarers
// problem: C. Strange Function

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll MOD=1e9+7;

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        ll ans=0,c=1;
        for (int i=2;i<45;i++){
            ll common=gcd(i,c);
            ll added=i/common;
            c*=added;
            ll ap=n/added;
            ans+=i*(n-ap);
            ans%=MOD;
            n=ap;
        }
        cout<<ans<<endl;
    }
}