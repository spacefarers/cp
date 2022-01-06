/*
ID: michael419
LANG: C++
TASK: money
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;


void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

long long dp[10005];

int main(){
    setIO("money");
    int v, n;
    cin>>v>>n;
    vector<int> coins(v);
    for (int i=0;i<v;i++){
        cin>>coins[i];
    }
    dp[0]=1;
    for (auto &i:coins){
        for (int j=1;j<=n;j++){
            if (j-i>=0) dp[j]+=dp[j-i];
        }
    }
    cout<<dp[n]<<endl;
}