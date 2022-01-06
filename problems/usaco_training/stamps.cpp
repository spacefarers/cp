/*
ID: michael419
LANG: C++
TASK: stamps
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

int dp[2000005];

int main(){
    setIO("stamps");
    int k, n;
    cin>>k>>n;
    vector<int> coins(n);
    for (int i=0;i<n;i++){
        cin>>coins[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0]=0;
    int pos=1;
    while (true){
        for (auto &i:coins){
            if (pos-i>=0) dp[pos]=min(dp[pos], dp[pos-i]+1);
        }
        if (dp[pos]>k) break;
        pos++;
    }
    cout<<pos-1<<endl;
}