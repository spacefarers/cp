#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll poww(ll a, ll b){
    ll ans=1;
    for (int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        ll n;
        cin>>n;
        for (ll j=1;poww(j, 3)<n;j++){
            ll z=0;
            for (ll k=1e5;k>=1;k/=2){
                while (poww(z+k, 3)+poww(j, 3)<=n) z+=k;
            }
            if (poww(j, 3)+poww(z, 3)==n){
                cout<<"YES"<<endl;
                goto cont;
            }
        }
        cout<<"NO"<<endl;
        cont:;
    }
}