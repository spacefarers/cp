/*
ID: michael419
LANG: C++
TASK: kimbits
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

ll N, L, I, pascal[40][40];
string temp;

void solve(ll n, ll l){
    if (n==0) return;
    ll s=pascal[n-1][l];
    if (s<=I){
        temp+="1";
        I-=s;
        solve(n-1, l-1);
    } else {
        temp+="0";
        solve(n-1, l);
    }
}

int main(){
    setIO("kimbits");
    cin>>N>>L>>I;
    I--;
    for (int i=0;i<=32;i++){
        pascal[0][i]=1;
    }
    for (int i=1;i<=32;i++){
        for (int j=0;j<=32;j++){
            if (j==0) pascal[i][j]=1;
            else pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
    }
    solve(N, L);
    cout<<temp<<endl;
}