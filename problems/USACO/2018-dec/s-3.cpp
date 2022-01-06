/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n, k;
vector<vi> board;
vector<vpi> connected;
bool visited[105][105];

void gravity(){
    bool applied_change=false;
    for (int i=n-1;i>0;i--){
        for (int j=0;j<10;j++){
            if (board[i][j]==0&&board[i-1][j]!=0){
                applied_change=true;
                board[i][j]=board[i-1][j];
                board[i-1][j]=0;
            }
        }
    }
    if (applied_change) gravity();
}

void dfs(int x, int y, int last_num, int last_place){
    if (visited[y][x]||x<0||y<0||x>=10||y>=n||board[y][x]!=last_num) return;
    visited[y][x]=true;
    connected[last_place].pb({y, x});
    dfs(x+1, y, last_num, last_place);
    dfs(x, y+1, last_num, last_place);
    dfs(x-1, y, last_num, last_place);
    dfs(x, y-1, last_num, last_place);
}

int main() {
    setIO("mooyomooyo");
    cin>>n>>k;
    board.rsz(n);
    for (int i=0;i<n;i++){
        board[i].rsz(10);
        string a;
        cin>>a;
        for (int j=0;j<10;j++){
            board[i][j]=a[j]-'0';
        }
    }
    while (true){
        memset(visited, false, sizeof(visited));
        bool change=false;
        gravity();
        int count=-1;
        for (int i=0;i<n;i++){
            for (int j=0;j<10;j++){
                if (!visited[i][j]){
                    if (board[i][j]==0){
                        visited[i][j]=true;
                        continue;
                    }
                    vpi a;
                    connected.pb(a);
                    count++;
                    dfs(j, i, board[i][j], count);
                }
            }
        }
        trav(i, connected){
            if (i.size()>=k) {
                change=true;
                trav(j, i){
                    board[j.first][j.second]=0;
//                    cout<<"("<<j.first<<", "<<j.second<<"), ";
                }
            }
        }
        connected.clear();
        if (!change) break;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<10;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    return 0;
}