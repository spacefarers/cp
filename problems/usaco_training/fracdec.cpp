/*
ID: michael419
LANG: C++
TASK: fracdec
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>

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

int main(){
    setIO("fracdec");
    ll n, d;
    cin>>n>>d;
    string ans;
    ans+=to_string(n/d)+".";
    map<int, int> mp;
    n%=d;
    while (true){
        n*=10;
        if (mp[n]!=0){
            if (n==0){
                if (ans[ans.size()-2]!='.') ans=ans.substr(0, ans.size()-1);
            } else {
                ans=ans.substr(0, mp[n])+"("+ans.substr(mp[n], ans.size()-mp[n])+")";
            }
            break;
        } else mp[n]=ans.size();
        ans+=to_string(n/d);
        n%=d;
    }
    int cur=0;
    while (cur<ans.size()){
        for (int i=0;i<76;i++){
            if (cur>=ans.size()) break;
            cout<<ans[cur++];
        }
        cout<<endl;
    }
}