/*
ID: michael419
LANG: C++
TASK: game1
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

int nums[105];
pair<int, int> dp[105][105];

int main(){
    setIO("game1");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        dp[i][i]={a, 0};
        nums[i]=a;
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<n-i;j++){
            auto a=dp[j][j+i-1], b=dp[j+1][j+i];
            if (nums[j+i]+a.s-a.f>nums[j]+b.s-b.f){
                dp[j][j+i]={a.s+nums[j+i], a.f};
            } else {
                dp[j][j+i]={b.s+nums[j], b.f};
            }
        }
    }
    cout<<dp[0][n-1].f<<" "<<dp[0][n-1].s<<endl;
}