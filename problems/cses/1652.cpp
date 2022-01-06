// created on 2021/7/10 by spacefarers
// problem: Forest Queries

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int prefix[1005][1005];

int main(){
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        string x;
        cin>>x;
        for (int j=1;j<=n;j++){
            prefix[i][j]=(x[j-1]=='*')?1:0;
            prefix[i][j]+=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    for (int i=0;i<q;i++){
        int a,b,c,d;
        cin>>c>>d>>a>>b;
        cout<<prefix[a][b]-prefix[c-1][b]-prefix[a][d-1]+prefix[c-1][d-1]<<endl;
    }
}