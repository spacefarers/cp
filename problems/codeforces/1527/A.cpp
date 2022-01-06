// created on 2021/6/14 by spacefarers
// problem: A. And Then There Were K

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        ll x=40;
        while (((ll)1<<x)>n) x--;
        cout<<((ll)1<<x)-1<<endl;
    }
}