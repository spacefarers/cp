// created on 2021/6/26 by spacefarers
// problem: B. Fix You

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

string board[105];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        for (int i=0;i<n;i++){
            cin>>board[i];
        }
        int ans=0;
        for (int i=0;i<n-1;i++){
            if (board[i][m-1]!='D') ans++;
        }
        for (int i=0;i<m-1;i++){
            if (board[n-1][i]!='R') ans++;
        }
        cout<<ans<<endl;
    }
}