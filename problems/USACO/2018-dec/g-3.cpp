// created on 2021/6/22 by spacefarers
// problem: Problem 3. Teamwork

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int nums[10005];
int dp[10005];
int K=30, log_table[10005], st[10005][31];

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int range_max(int L,int R){
    int j=log_table[R-L+1];
    return max(st[L][j],st[R-(1<<j)+1][j]);
}

int main(){
    setIO("teamwork");
    memset(st,0,sizeof st);
    log_table[1]=0;
    for (int i=2;i<10005;i++){
        log_table[i]=log_table[i/2]+1;
    }
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>nums[i];
        st[i-1][0]=nums[i];
    }
    for (int i=1;i<=K;i++){
        for (int j=0;j+(1<<i)<=n;j++){
            st[j][i]=max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            if (i-j<0) break;
            dp[i]=max(dp[i],dp[i-j]+j*range_max(i-j,i-1));
        }
    }
    cout<<dp[n]<<endl;
}