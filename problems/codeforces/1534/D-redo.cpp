// created on 2021/6/14 by spacefarers
// problem: D. Lost Tree
// main idea: tree are bipartite graphs, meaning if we can split it into layers and select and query the even/odd ones depending on which one is less.

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

vector<int> answers[2005];
vector<pair<int,int>> edges;

int n;

vector<int> query(int x){
    if (!answers[x].empty()) return answers[x];
    cout<<"? "+to_string(x)<<endl;
    cout.flush();
    vector<int> ans(n);
    for (int i=0;i<n;i++){
        cin>>ans[i];
    }
    answers[x]=ans;
    return ans;
}

int main(){
    cin>>n;
    vector<int> resp=query(1);
    int evens=0,odds=0;
    for (auto i:resp){
        if (i%2) odds++;
        else evens++;
    }
    for (int i=0;i<n;i++){
        if ((resp[i]%2)^(odds>=evens)){
            vector<int> resp2=query(i+1);
            for (int j=0;j<n;j++){
                if (resp2[j]==1) edges.emplace_back(i+1,j+1);
            }
        }
    }
    cout<<"!"<<endl;
    for (auto i:edges){
        cout<<i.f<<" "<<i.s<<endl;
    }
}