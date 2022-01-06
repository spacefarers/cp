// created on 2021/6/22 by spacefarers
// problem: Problem 1. Snakes

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int groups[405];
int dp[405][405]; // dp[i][j]: from 1-i,changed j times;

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
//    setIO("snakes");
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>groups[i];
    }
//    k++;
//    dp[0][0][0]=0;
    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;
    for (int i=2;i<=n;i++){
        int max_num=0;
        dp[i][0]=0;
        for (int l=1;l<=i;l++){
            dp[i][0]-=groups[l];
            max_num=max(max_num,groups[l]);
        }
        dp[i][0]+=max_num*i;
        for (int j=1;j<i;j++){
            int range_max=0,range_sum=0;
            for (int l=j+1;l<=i;l++){
                range_max=max(range_max,groups[l]);
                range_sum+=groups[l];
            }
            for (int l=0;l<k;l++){
                dp[i][l+1]=min(dp[i][l+1],dp[j][l]+range_max*(i-j)-range_sum);
            }
        }
    }
    cout<<dp[n][k]<<endl;
}