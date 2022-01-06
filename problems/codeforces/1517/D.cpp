// created on 2021/7/5 by spacefarers
// problem: D. Explorer Space

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll dp[505][505][25],weight_hori[505][505],weight_vert[505][505];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        for (int j=0;j<m-1;j++){
            cin>>weight_hori[i][j];
        }
    }
    for (int i=0;i<n-1;i++){
        for (int j=0;j<m;j++){
            cin>>weight_vert[i][j];
        }
    }
    if (k%2){
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout<<-1<<" ";
            }
            cout<<endl;
        }
        exit(0);
    }
    for (int i=1;i<=k/2;i++){
        for (int j=0;j<n;j++){
            for (int l=0;l<m;l++){
                ll c_ans=1e9;
                if (j!=0) c_ans=min(c_ans,dp[j-1][l][i-1]+weight_vert[j-1][l]);
                if (j!=n-1) c_ans=min(c_ans,dp[j+1][l][i-1]+weight_vert[j][l]);
                if (l!=0) c_ans=min(c_ans,dp[j][l-1][i-1]+weight_hori[j][l-1]);
                if (l!=m-1) c_ans=min(c_ans,dp[j][l+1][i-1]+weight_hori[j][l]);
                dp[j][l][i]=c_ans;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<dp[i][j][k/2]*2<<" ";
        }
        cout<<endl;
    }
}