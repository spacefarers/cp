// created on 2021/6/13 by spacefarers
// problem: A. Colour the Flag

#include <iostream>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

string board[55];
bool visited[55][55];
int n,m;
bool ok;
int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y, char color){
    if (x<0||x>=n||y<0||y>=m) return;
    if (visited[x][y]) return;
    visited[x][y]=true;
    if (board[x][y]!='.'&&board[x][y]!=color){
        ok=false;
        return;
    }
    board[x][y]=color;
    for (auto i:dirs){
        dfs(x+i[0],y+i[1],(color=='R')?'W':'R');
    }
}

int main(){
    int t;
    cin>>t;
    while (t--){
        ok=true;
        memset(visited,false,sizeof visited);
        cin>>n>>m;
        for (int i=0;i<n;i++){
            cin>>board[i];
        }
        bool found=false;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]!='.') {
                    found=true;
                    dfs(i,j,board[i][j]);
                }
            }
        }
        if (!found) dfs(0,0,'R');
        if (ok){
            cout<<"YES"<<endl;
            for (int i=0;i<n;i++){
                cout<<board[i]<<endl;
            }
        } else cout<<"NO"<<endl;
    }
}