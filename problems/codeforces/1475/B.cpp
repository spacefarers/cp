#include <iostream>

using namespace std;

bool dp[1000005];

int main(){
    dp[0]=true;
    dp[2020]=true;
    for (int i=2021;i<1000005;++i){
        if (dp[i-2020]||dp[i-2021]) dp[i]=true;
    }
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        cout<<(dp[n]?"YES":"NO")<<endl;
    }
}