// created on 2021/7/6 by spacefarers
// problem: C. Count Triangles
// Very good intuition problem

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll prefix[1000005];

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for (ll i=a;i<=b;i++){
        prefix[i+b]++;
        prefix[i+c+1]--;
    }
    for (int i=1;i<1e6+5;i++){
        prefix[i]+=prefix[i-1];
    }
    for (int i=1;i<1e6+5;i++){
        prefix[i]+=prefix[i-1];
    }
    for (ll i=c;i<=d;i++){
        ans+=prefix[(ll)1e6+4]-prefix[i];
    }
    cout<<ans<<endl;
}