#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n, board[300][300], c_ans;
bool visited[300][300], used[2], counted[300][300];

void dfs(int x, int y, int num1, int num2){
    if (visited[x][y]) return;
    visited[x][y]=true;
    if (board[x][y]==num1) used[0]=true;
    else if (board[x][y]==num2) used[1]=true;
    else return;
    counted[x][y]=true;
    c_ans++;
    int num2_temp=num2;
    if (x>0){
        if (num2==-2) num2_temp=board[x-1][y];
        dfs(x-1, y, num1, num2_temp);
    }
    if (x<n-1){
        if (num2==-2) num2_temp=board[x-1][y];
        dfs(x+1, y, num1, num2_temp);
    }
    if (y>0){
        if (num2==-2) num2_temp=board[x-1][y];
        dfs(x, y-1, num1, num2_temp);
    }
    if (y<n-1){
        if (num2==-2) num2_temp=board[x-1][y];
        dfs(x, y+1, num1, num2_temp);
    }
}
int main() {
    setIO("multimoo");
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    int f_ans=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            c_ans=0;
            if (!counted[j][i]){
                memset(visited, false, sizeof(visited));
                dfs(j, i, board[j][i], -1);
            }
            f_ans=max(f_ans, c_ans);
        }
    }
    memset(counted, false, sizeof(counted));
    int f_ans2=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            c_ans=0;
            if (!counted[j][i]){
                memset(visited, false, sizeof(visited));
                dfs(j, i, board[j][i], -2);
            }
            f_ans2=max(f_ans2, c_ans);
        }
    }
    cout<<f_ans<<endl<<f_ans2;
    return 0;
}