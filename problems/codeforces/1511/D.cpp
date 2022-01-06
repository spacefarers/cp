// created on 2021/7/3 by spacefarers
// problem: D. Min Cost String

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

#define ll long long
#define f first
#define s second

using namespace std;

int n,k;
bool used[26][26];
string c;

void dfs(){
    if (c.size()==k*k+1||c.size()==n){
        if (c.size()>1&&c.back()==c.front()) c.pop_back();
        string ans;
        for (int i=0;i<n/c.size();i++){
            ans+=c;
        }
        ans+=c.substr(0,n-ans.size());
        cout<<ans<<endl;
        exit(0);
    }
    for (int i=0;i<k;i++){
        if (!used[c.back()-'a'][i]){
            used[c.back()-'a'][i]=true;
            c+=char('a'+i);
            dfs();
            c.pop_back();
            used[c.back()-'a'][i]=false;
        }
    }
}

int main(){
    cin>>n>>k;
    c="a";
    dfs();
}