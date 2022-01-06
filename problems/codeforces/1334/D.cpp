// created on 2021/7/6 by spacefarers
// problem: D. Minimum Euler Cycle

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
        ll n,l,r;
        cin>>n>>l>>r;
        ll lev=1,c=1;
        while (c<=l&&lev<n){
            c+=(n-lev++)*2;
        }
        lev--;
        c-=(n-lev)*2;
        while (c<=r){
            for (ll i=lev+1;i<=n;i++){
                if (c<=r&&c++>=l)
                    cout<<lev<<" ";
                if (c<=r&&c++>=l)
                    cout<<i<<" ";
            }
            if (c>r) break;
            if (lev==n){
                if (c<=r&&c++>=l)
                    cout<<1;
            }
            lev++;
        }
        cout<<endl;
    }
}