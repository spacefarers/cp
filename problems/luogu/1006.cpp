#include <iostream>

using namespace std;

int n, m, inputs[55][55], dp[55][55][55][55];

int max_ele(int a,int b,int c,int d){
    if (b>a)
        a = b;
    if (c>a)
        a = c;
    if (d>a)
        a = d;
    return a;
}

int main(){
    cin>>m>>n;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin>>inputs[i][j];
        }
    }
    dp[1][1][1][1] = 0;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            for (int a=1;a<=m;a++){
                for (int b=j+1;b<=n;b++){
                    dp[i][j][a][b] = max_ele(dp[i-1][j][a-1][b], dp[i-1][j][a][b-1], dp[i][j-1][a-1][b], dp[i][j-1][a][b-1])+inputs[i][j]+inputs[a][b];
                }
            }
        }
    }
    cout<<dp[m][n-1][m-1][n]<<endl;
}
