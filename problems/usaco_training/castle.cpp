/*
ID: michael419
LANG: C++
TASK: castle
*/

#include <iostream>
#include <cstring>

using namespace std;

#define f first
#define s second

bool paths[55][55][4], vis[55][55]; // left, up, right, down
int m, n;
int rooms=0, max_size=0, c_size=0, room_num[55][55], rooms_size[55*55];
pair<pair<int, int>, pair<int, char>> max_comb;
pair<int, int> dir[4]={{0,  -1},
                       {-1, 0},
                       {0,  1},
                       {1,  0}};

void dfs(int x, int y){
    if (vis[x][y]||x<0||y<0||x>=n||y>=m) return;
    c_size++;
    room_num[x][y]=rooms;
    vis[x][y]=true;
    for (int i=0;i<4;i++){
        if (paths[x][y][i]){
            dfs(x+dir[i].first, y+dir[i].second);
        }
    }
}

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    setIO("castle");
    cin>>m>>n;
    memset(paths, true, sizeof paths);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int a;
            cin>>a;
            if (a>=8){
                paths[i][j][3]=false;
                a-=8;
            }
            if (a>=4){
                paths[i][j][2]=false;
                a-=4;
            }
            if (a>=2){
                paths[i][j][1]=false;
                a-=2;
            }
            if (a==1) paths[i][j][0]=false;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!vis[i][j]){
                rooms++;
                c_size=0;
                dfs(i, j);
                rooms_size[rooms]=c_size;
                max_size=max(max_size, c_size);
            }
        }
    }
    memset(vis, false, sizeof vis);
    for (int x=0;x<n;x++){
        for (int y=0;y<m;y++){
            for (int i=1;i<3;i++){
                int next_room=room_num[x+dir[i].first][y+dir[i].second];
                if (next_room==room_num[x][y]) continue;
                int cc_size=rooms_size[next_room]+rooms_size[room_num[x][y]];
                if (cc_size>max_comb.f.f||(cc_size==max_comb.f.f&&
                                           (y<max_comb.f.s||
                                            (y==max_comb.f.s&&(x>max_comb.s.f||(x==max_comb.s.f&&i==1)))))){
                    max_comb={{cc_size, y},{x,(i==1)?'N':'E'}};
                }
            }
        }
    }
    cout<<rooms<<endl<<max_size<<endl<<max_comb.f.f<<endl<<max_comb.s.f+1<<" "<<max_comb.f.s+1 <<" "<<max_comb.s.s<<endl;
}