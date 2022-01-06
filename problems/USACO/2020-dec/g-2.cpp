// created on 2021/6/24 by spacefarers
// problem: Problem 2. Bovine Genetics

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll dp[100005][4][4][4],MOD=1e9+7; // 当前长度；前一个结尾；现在开头；现在结尾
char code[4]={'A','G','C','T'};

int main(){
    string x;
    cin>>x;
    int n=(int)x.size();
    x=' '+x;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (x[1]=='?'||code[j]==x[1]) dp[1][i][j][j]=1;
        }
    }
    for (int i=2;i<=n;i++){
        for (int j=0;j<4;j++){
            if (x[i]!='?'&&x[i]!=code[j]) continue;
            for (int k=0;k<4;k++){
                for (int l=0;l<4;l++){
                    for (int m=0;m<4;m++){
                        if (m!=j){
                            dp[i][k][l][j]+=dp[i-1][k][l][m];
                            dp[i][k][l][j]%=MOD;
                        }
                        if (k==m){
                            dp[i][l][j][j]+=dp[i-1][k][l][m];
                            dp[i][l][j][j]%=MOD;
                        }
                    }
                }
            }
        }
    }
    ll ans=0;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            ans+=dp[n][i][j][i];
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}