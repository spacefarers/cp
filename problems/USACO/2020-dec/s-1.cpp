#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> paths[100005];
int ans=0;

void dfs(int x, int from){
    int t=1, a=(int)paths[x].size()-1;
    if (x==1) a++;
    while (t<=a){
        t*=2;
        ans++;
    }
    for (int &i:paths[x]){
        if (i!=from) {
            ans++;
            dfs(i, x);
        }
    }
}

int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(1, 1);
    cout<<ans<<endl;
}