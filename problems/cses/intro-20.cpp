// Grid Paths

#include <iostream>
#include <vector>

using namespace std;

string a;
int dir[4][2]={{-1, 0},
               {0,  -1},
               {1,  0},
               {0,  1}}; // up, left, down, right
char dirs[4]={'U', 'L', 'D', 'R'};
int ans=0;
//int calls=0;
string c;
bool vis[10][10];

bool valid(int new_x, int new_y){
    return new_x>=0&&new_y>=0&&new_x<7&&new_y<7&&!vis[new_x][new_y];
}

void solve(int x, int y){
    if (c.size()==a.size()){
        ans++;
        return;
    }
    if (x==6&&y==0&&c.size()!=a.size()) return;
    if (x<0||y<0||x>=7||y>=7) return;
    for (int i=0;i<4;i++){
        if (a[c.size()]!='?'&&a[c.size()]!=dirs[i]) continue;
        int new_x=x+dir[i][0];
        int new_y=y+dir[i][1];
        if (valid(new_x, new_y)){
            int forward_x=new_x+dir[i][0];
            int forward_y=new_y+dir[i][1];
            int turn1_x=new_x, turn2_x=new_x, turn1_y=new_y, turn2_y=new_y;
            if (i==0||i==2){
                turn1_y++;
                turn2_y--;
            } else {
                turn1_x++;
                turn2_x--;
            }
            if (!valid(forward_x, forward_y)&&valid(turn1_x, turn1_y)&&valid(turn2_x, turn2_y)){
                continue;
            }
            string bp=c;
            c+=dirs[i];
            vis[new_x][new_y]=true;
            solve(new_x, new_y);
            c=bp;
            vis[new_x][new_y]=false;
        }
    }
}

int main(){
    cin>>a;
    vis[0][0]=true;
    solve(0, 0);
    cout<<ans<<endl;
}