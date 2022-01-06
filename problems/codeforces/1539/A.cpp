// created on 2021/6/23 by spacefarers
// problem: A. Contest Start

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int k;
    cin>>k;
    while (k--){
        ll n,x,t;
        cin>>n>>x>>t;
        ll sec=t/x;
        sec=min(sec,n-1);
        ll ans=sec*(n);
        ans-=(sec+1)*sec/2;
        cout<<ans<<endl;
    }
}