#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


string c, a;
map<char, int> counts1;
map<char, int> counts2;
vector<string> ans;

void dfs(){
    if (c.size()==a.size()){
        ans.push_back(c);
        return;
    }
    map<char, bool> used;
    for (char & i : a){
        if (used[i]) continue;
        if (counts2[i]>=counts1[i]) continue;
        used[i]=true;
        c+=i;
        counts2[i]++;
        dfs();
        counts2[i]--;
        c=c.substr(0, c.size()-1);
    }
}

int main(){
    cin>>a;
    for (char & i : a){
        counts1[i]++;
    }
    dfs();
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for (string &i:ans){
        cout<<i<<endl;
    }
}