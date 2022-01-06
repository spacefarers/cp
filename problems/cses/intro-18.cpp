// Chessboard and Queens

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<char> avails;
map<char, int> mp;
bool visited[7][7];
string a;
int ans=0;

bool inValid(int x, int y){
    return x<0||y<0||x>6||y>6||visited[x][y];
}

void dfs(int x, int y, int dep=0){
    if (x==6&&y==6){
        if (dep==48) ans++;
        else return;
    }
    if (inValid(x, y)) return;
    visited[x][y]=true;
    if (inValid(x, y+1)&&inValid(x, y-1)&&!inValid(x-1, y)&&!inValid(x+1, y)) {
        cout<<"ha"<<endl;
        return;
    }
    if (inValid(x+1, y)&&inValid(x-1, y)&&!inValid(x, y+1)&&!inValid(x, y-1)) return;
    cout<<x<<" "<<y<<" "<<dep<<" "<<ans<<endl;
    if (a[dep]=='R'||a[dep]=='?') {
        dfs(x+1, y, dep+1);
        visited[x+1][y]= false;
    }
    if (a[dep]=='L'||a[dep]=='?') {
        dfs(x-1, y, dep+1);
        visited[x - 1][y] = false;
    }
    if (a[dep]=='D'||a[dep]=='?') {
        dfs(x, y - 1, dep + 1);
        visited[x][y - 1] = false;
    }
    if (a[dep]=='U'||a[dep]=='?'){
        dfs(x, y+1, dep+1);
        visited[x][y+1]= false;
    }
}

int main(){
    cin>>a;
    for (int i=0;i<48;i++){
        mp[a[i]]++;
    }
    dfs(0, 0);
    cout<<ans<<endl;
    return 0;
}