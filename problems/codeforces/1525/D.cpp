// created on 2021/6/17 by spacefarers
// problem: D. Armchairs
// worth redoing, need intuition for dp

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int dp[5005][5005];

int main(){
    int n;
    cin>>n;
    memset(dp,0x3f,sizeof dp);
    vector<bool> chairs;
    vector<int> pos;
    for (int i=0;i<n;i++){
        bool a;
        cin>>a;
        if (a) pos.push_back(i);
        chairs.push_back(a);
    }
    for (int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            dp[i][j]=min(dp[i-1][j],((j>pos.size()||chairs[i-1])?(int)1e9:dp[i-1][j-1]+abs(i-1-pos[j-1])));
        }
    }
    cout<<dp[n][pos.size()]<<endl;
}