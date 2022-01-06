// created on 6/19/21 by spacefarers
// problem: B - Savings

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    ll n;
    cin>>n;
    ll z=-1;
    for (ll i=1e7;i>=1;i/=2){
        while ((z+i)*(z+i+1)<n*2) z+=i;
    }
    cout<<z+1<<endl;
}