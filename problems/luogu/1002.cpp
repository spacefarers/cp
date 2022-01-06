#include <iostream>

using namespace std;

long long a, b, c, d, dp[25][25];

int main(){
    cin>>a>>b>>c>>d;
    dp[1][1]=1;
    a++;b++;c++;d++;
    for (int i=1;i<=b;i++){
        for (int j=1;j<=a;j++){
            if (i==1&&j==1) continue;
            dp[j][i] = dp[j][i-1]+dp[j-1][i];
            if ((i==d-1&&j==c-2)||(i==d-1&&j==c+2)||(i==d+1&&j==c-2)||(i==d+1&&j==c+2)||(i==d-2&&j==c-1)||(i==d-2&&j==c+1)||(i==d+2&&j==c-1)||(i==d+2&&j==c+1)||(i==d&&j==c))
                dp[j][i]=0;
        }
    }
    cout<<dp[a][b]<<endl;
}

