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
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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

bool board[1005][1005];
int n;
bool visited[1005][1005];
int ans[1000005][2];
int c=0;

void dfs(int x, int y){
    if (visited[x][y]||!board[x][y]) {
        visited[x][y]=true;
        return;
    }
    visited[x][y]=true;
    ans[c][0]++;
    if (x==0||!board[x-1][y]) ans[c][1]++;
    if (x==n-1||!board[x+1][y]) ans[c][1]++;
    if (y==0||!board[x][y-1]) ans[c][1]++;
    if (y==n-1||!board[x][y+1]) ans[c][1]++;
    if (x!=0)
        dfs(x-1, y);
    if (x!=n-1)
        dfs(x+1, y);
    if (y!=0)
        dfs(x, y-1);
    if (y!=n-1)
        dfs(x, y+1);
}

int main() {
    setIO("perimeter");
    cin>>n;
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        for (int j=0;j<n;j++){
            if (a[j]=='#')
                board[i][j]=true;
            else
                board[i][j]=false;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (!visited[i][j]&&board[i][j]){
                dfs(i, j);
                c++;
            }
        }
    }
    int max_item=0;
    for (int i=1;i<c;i++){
        if (ans[max_item][0]<ans[i][0]||(ans[max_item][0]==ans[i][0]&&ans[max_item][1]>ans[i][1])){
            max_item=i;
        }
    }
    cout<<ans[max_item][0]<<" "<<ans[max_item][1]<<endl;
    return 0;
}