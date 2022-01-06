// created on 2021/7/18 by spacefarers
// problem: C - 1, 2, 3 - Decomposition

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

map<ll,int> memo;

int solve(ll N){
    if (N<=0) return 0;
    if (memo[N]!=0) return memo[N];
    ll n=N/10;
    int x=(int)(N%10);
    int prev1=solve(n),prev2=solve(n-1);
    int ans;
    if (1<=x&&x<=3&&prev1<=1) ans=1;
    else if (2<=x&&x<=6&&prev1<=2) ans=2;
    else if (3<=x&&x<=9&&prev1<=3) ans=3;
    else if (4<=x&&x<=9&&prev1<=4||prev2<=4&&x<=2) ans=4;
    else ans=5;
    memo[N]=ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        ll x;
        cin>>x;
        cout<<solve(x)<<endl;
    }
}