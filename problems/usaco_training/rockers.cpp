/*
ID: michael419
LANG: C++
TASK: rockers
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


int n, t, m;
int dp[25][25][25], length[25];

int main(){
    setIO("rockers");
    cin>>n>>t>>m;
    for (int i=0;i<n;i++){
        cin>>length[i+1];
    }
    int best=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<=t;j++){
            for (int k=0;k<=n;k++){
                for (int l=k+1;l<=n;l++){
                    if (j+length[l]<=t){
                        if (dp[i][j][k]+1>dp[i][j+length[l]][l]) dp[i][j+length[l]][l]=dp[i][j][k]+1;
                    } else {
                        if (dp[i][j][k]+1>dp[i+1][length[l]][l]) dp[i+1][length[l]][l]=dp[i][j][k]+1;
                    }
                }
                best=max(best, dp[i][j][k]);
            }
        }
    }
    cout<<best<<endl;
}