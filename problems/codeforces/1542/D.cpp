// created on 2021/7/3 by spacefarers
// problem: D. Priority Queue

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll NCR[505][505],MOD=998244353;

void precomp(){
    NCR[0][0]=1;
    for (int i=1;i<505;i++){
        NCR[i][0]=NCR[i][i]=1;
        for (int j=1;j<i;j++){
            NCR[i][j]=NCR[i-1][j-1]+NCR[i-1][j];
            NCR[i][j]%=MOD;
        }
    }
}

int main(){
    int n;
    cin>>n;
    precomp();
    int pluses=0,sum=0;
    vector<int> nums;
    for (int i=0;i<n;i++){
        char a;
        cin>>a;
        int b=-1;
        if (a=='+'){
            cin>>b;
            pluses++;
            sum+=b;
        }
        nums.push_back(b);
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=sum*NCR[n][i];
        ans-=sum*i;
    }

}