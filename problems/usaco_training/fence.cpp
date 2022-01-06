/*
ID: michael419
LANG: C++
TASK: fence
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int paths[505][505];
int deg[505];
vector<int> ans;

void dfs(int x){
    for (int i=0;i<505;i++){
        if (paths[x][i]){
            paths[x][i]--;paths[i][x]--;
            dfs(i);
        }
    }
    ans.push_back(x);
}

int main(){
    setIO("fence");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        paths[a][b]++;paths[b][a]++;
        deg[a]++;deg[b]++;
    }
    vector<int> odd_node;
    for (int i=0;i<505;i++){
        if (deg[i]%2) odd_node.push_back(i);
    }
    if (!odd_node.empty()&&odd_node.size()!=2){
        cout<<"IMPOSSIBLE"<<endl;
    }
    if (!odd_node.empty()){
        dfs(odd_node.front());
    } else dfs(1);
    reverse(ans.begin(), ans.end());
    for (auto &i:ans){
        cout<<i<<endl;
    }
}