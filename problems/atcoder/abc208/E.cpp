// created on 2021/7/4 by spacefarers
// problem: E - Digit Products

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define ll long long
#define f first
#define s second

using namespace std;

ll solve(ll n,ll k){
    string x=to_string(n);
    if (x.size()<2){
        return min(n,k)+1;
    }
    ll top=stol(x.substr(0,1));
    ll ans=0;
    for (int i=0;i<=top;i++){
        int j=i;
        if (j==0) j=1;
        ans+=solve(stol(x.substr(1,x.size()-1)),k/j);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<endl;
}