/*
ID: michael419
LANG: C++
TASK: prefix
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;


void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

bool can_make[200005];

int main(){
    setIO("prefix");
    map<string, bool> mp;
    int max_size=0;
    while (true){
        string a;
        cin>>a;
        if (a==".") break;
        mp[a]=true;
        max_size=max(max_size, (int)a.size());
    }
    string x, f;
    while (cin>>x){
        f+=x;
    }
    can_make[0]=true;
    for (int i=1;i<=f.size();i++){
        for (int j=1;j<=max_size;j++){
            if (i-j>=0&&can_make[i-j]&&mp[f.substr(i-j, j)]) can_make[i]=true;
        }
    }
    int ans=0;
    for (int i=0;i<=f.size();i++){
        if (can_make[i]) ans=i;
    }
    cout<<ans<<endl;
}