// created on 6/19/21 by spacefarers
// problem: C - Swappable

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    ll n;
    cin>>n;
    map<ll,ll> mp;
    ll ans=0;
    for (ll i=0;i<n;i++){
        ll a;
        cin>>a;
        ans+=i;
        ans-=mp[a]++;
    }
    cout<<ans<<endl;
}