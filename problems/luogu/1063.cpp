#include <iostream>

using namespace std;

int dp[205][205], chain[205];

int main(){
    int N;
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>chain[i];
        chain[i+N]=chain[i];
    }
    for (int i=2*N-1;i>=0;i--){
        for (int j=i+2;j<2*N;j++){
            if (j-i==3){
                dp[i][j]=chain[i]*chain[i+1]*chain[j];
            } else {
                for (int k=i+2;k<j-2;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k]);
                }
            }
        }
    }
}