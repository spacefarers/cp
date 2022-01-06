// created on 2021/6/14 by spacefarers
// problem: D. Lost Tree

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int parent[2005];
int n,fixed_nodes=1;
vector<int> answers[2005];

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

void dfs(int root, const vector<int> &dists){
    for (int i=1;i<=dists.size();i++){
        if (dists[i-1]==1&&parent[i]==0){

        }
    }
}

int main(){
    cin>>n;
    parent[1]=-1;
    vector<int> init;
    for (int i=2;i<=n;i++){
        init.push_back(i);
    }
    dfs(1,init);
    cout<<"!"<<endl;
    for (int i=2;i<=n;i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
}