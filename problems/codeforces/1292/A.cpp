// created on 2021/7/5 by spacefarers
// problem: A. NEKO's Maze Game

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

bool board[2][100005];

bool check_fault(int x){
    bool full_block=board[0][x]&&board[1][x]||board[0][x+1]&&board[1][x+1];
    bool diag_block=board[0][x]&&board[1][x+1]||board[1][x]&&board[0][x+1];
    return full_block||diag_block;
}

int main(){
    int n,q;
    cin>>n>>q;
    int faults=0;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;
        faults-=check_fault(b-1);
        faults-=check_fault(b);
        board[a][b]=!board[a][b];
        faults+=check_fault(b-1);
        faults+=check_fault(b);
        if (faults) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}