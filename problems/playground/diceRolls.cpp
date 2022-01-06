// created on 9/17/21 by spacefarers
// problem: 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll dp[25];

int main(){
    dp[0]=1;
    for (int i=1;i<=24;i++){
        for (int j=1;j<=6;j++){
            if (i-j>=0&&i-j<=18) dp[i]+=dp[i-j];
        }
    }
    ll wins=0,tot=0;
    for (int i=19;i<=21;i++){
        wins+=dp[i];
        tot+=dp[i];
    }
    for (int i=22;i<=24;i++){
        tot+=dp[i];
    }
    cout<<double(wins)/tot<<endl;
}
