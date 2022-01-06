// created on 2021/6/21 by spacefarers
// problem: D. Multiplication Table

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll n,m,k;
bool validate(ll x){
    ll c=0;
    for (ll i=1;i<=m;i++){
        if (i>=x) break;
        c+=min(x/i,n);
        if (x%i==0&&x/i<=n) c--;
        if (c>=k) return false;
    }
    return true;
}

int main(){
    cin>>n>>m>>k;
    ll z=-1;
    for (ll i=1e10;i>=1;i/=2){
        while (validate(i+z)) z+=i;
    }
    cout<<z<<endl;
}