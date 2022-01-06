/*
ID: michael419
LANG: C++
TASK: concom
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int control[105][105];

int main(){
    setIO("concom");
    int n;
    cin>>n;
    set<pair<int, int>> concom, new_concom;
    set<pair<int, int>> ans;
    for (int i=0;i<n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        control[a][b]=c;
        if (c>50){
            concom.insert({a, b});
            ans.insert({a, b});
        }
    }
    while (true){
        for (auto &i:concom){
            for (int j=1;j<=100;j++){
                control[i.first][j]+=control[i.second][j];
                if (control[i.first][j]>50&&ans.find({i.first, j})==ans.end()){
                    new_concom.insert({i.first, j});
                    ans.insert({i.first, j});
                }
            }
        }
        if (new_concom.empty()) break;
        concom=new_concom;
        new_concom.clear();
    }
    for (auto &i:ans){
        if (i.first==i.second) continue;
        cout<<i.first<<" "<<i.second<<endl;
    }
}