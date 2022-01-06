// created on 2021/7/1 by spacefarers
// problem: Static Range Minimum Queries

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

#define MAX 200005

int K=30, log_table[MAX], st[MAX][31];

int main(){
    int n,q;
    cin>>n>>q;
    memset(st, 0x3f, sizeof st);
    log_table[1]=0;
    for (int i=2;i<MAX;i++){
        log_table[i]=log_table[i/2]+1;
    }
    for (int i=0;i<n;i++) cin>>st[i][0];
    for (int i=1;i<=K;i++){
        for (int j=0;j+(1<<i)<=n;j++){
            st[j][i]=min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
        }
    }
    for (int i=0;i<q;i++){
        int L,R;
        cin>>L>>R;
        L--,R--;
        int j=log_table[R-L+1];
        cout<<min(st[L][j], st[R-(1<<j)+1][j])<<endl;
    }
}