/*
ID: michael419
LANG: C++
TASK: zerosum
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

vector<vector<int>> opts;
vector<int> c;
int n;

void gen(){
    if (c.size()==n-1){
        opts.push_back(c);
        return;
    }
    c.push_back(0);
    gen();
    c.pop_back();
    c.push_back(1);
    gen();
    c.pop_back();
    c.push_back(-1);
    gen();
    c.pop_back();
}

int main(){
    setIO("zerosum");
    cin>>n;
    gen();
    for (auto &i:opts){
        string item="1";
        int ans=0;
        for (int j=2;j<=n;j++){
            if (i[j-2]==-1){
                ans+=stoi(item);
                item="-"+to_string(j);
            } else if (i[j-2]==0){
                item+=to_string(j);
            } else {
                ans+=stoi(item);
                item=to_string(j);
            }
        }
        ans+=stoi(item);
        if (ans==0){
            for (int j=1;j<=n;j++){
                cout<<j;
                if (j!=n){
                    if (i[j-1]==-1) cout<<"-";
                    else if (i[j-1]==0) cout<<" ";
                    else cout<<"+";
                }
            }
            cout<<endl;
        }
    }
}