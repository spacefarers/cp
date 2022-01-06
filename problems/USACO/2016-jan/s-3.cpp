#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<pair<int, int>, vector<pair<int, int>>> paths;
map<pair<int, int>, bool> visited;

int ans=0;

void dfs(pair<int, int> a, pair<int, int> from){
    if (visited[a]){
        ans++;
        return;
    }
    visited[a]=true;
    map<pair<int, int>, bool> temp;
    for (auto &i:paths[a]){
        if (i==from||temp[i]) continue;
        temp[i]=true;
        dfs(i, a);
    }
}

int main(){
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    int n;
    string a;
    cin>>n>>a;
    pair<int, int> c={0, 0};
    for (int i=0;i<n;i++){
        pair<int, int> new_c=c;
        if (a[i]=='N'){
            new_c.first++;
        } else if (a[i]=='E'){
            new_c.second--;
        } else if (a[i]=='W'){
            new_c.second++;
        } else {
            new_c.first--;
        }
        paths[c].push_back(new_c);
        paths[new_c].push_back(c);
        c=new_c;
    }
    dfs({0, 0}, {-10000, -100000});
    cout<<ans/2<<endl;
}