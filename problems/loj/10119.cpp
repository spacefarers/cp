#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100005

int K=30,log_table[MAX],st[MAX][31];

int main(){
    memset(st,0x3f,sizeof st);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    log_table[1]=0;
    for (int i=2;i<MAX;i++){
        log_table[i]=log_table[i/2]+1;
    }
    int n,q;
    cin>>n>>q;
    for (int i=0;i<n;i++) cin>>st[i][0];
    for (int i=1;i<=K;i++){
        for (int j=0;j+(1<<i)<=n;j++){
            st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
    // Sample Usage 0 indexed
    int L,R;
    while (q--){
        cin>>L>>R;
        L--,R--;
        int j=log_table[R-L+1];
        cout<<max(st[L][j],st[R-(1<<j)+1][j])<<endl;
    }
}