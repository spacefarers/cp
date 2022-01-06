// created on 2021/7/30 by spacefarers
// problem: C. Coin Rows

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int board[2][100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(board,0,sizeof board);
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>board[0][i];
        }
        for (int i=1;i<=n;i++){
            cin>>board[1][i];
            board[1][i]+=board[1][i-1];
        }
        for (int i=n;i>0;i--){
            board[0][i]+=board[0][i+1];
        }
        int score=1e9;
        for (int i=1;i<=n;i++){
            score=min(score,max(board[1][i-1],board[0][i+1]));
        }
        cout<<score<<endl;
    }
}