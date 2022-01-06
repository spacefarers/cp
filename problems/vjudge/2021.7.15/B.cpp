// created on 2021/7/15 by spacefarers
// problem: B - Link Cut Centroids

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;

vector<int> paths[100005];
int subtrees[100005];

int dfs(int x,int par){
    int subs=0;
    for (auto i:paths[x]){
        if (i==par) continue;
        subs+=dfs(i,x);
    }
    subtrees[x]=subs+1;
    return subtrees[x];
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(subtrees,0,sizeof subtrees);
        for (auto &i:paths) i.clear();
        int n;
        cin>>n;
        for (int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            paths[a].push_back(b);
            paths[b].push_back(a);
        }
        dfs(1,-1);
        int min_centroid=1e9;
        set<int> points;
        for (int i=1;i<=n;i++){
            int c_max=0;
            for (auto j:paths[i]){
                int c_paths;
                if (subtrees[j]<subtrees[i]) c_paths=subtrees[j];
                else c_paths=n-subtrees[i];
                c_max=max(c_max,c_paths);
            }
            if (c_max<min_centroid){
                min_centroid=c_max;
                points.clear();
            }
            if (c_max<=min_centroid){
                points.insert(i);
            }
        }
        if (points.size()==1){
            cout<<1<<" "<<paths[1].front()<<endl;
            cout<<1<<" "<<paths[1].front()<<endl;
            goto cont;
        }
        for (auto i:points){
            for (auto j:points){
                if (i==j) continue;
                for (auto k:paths[j]){
                    if (k==i) continue;
                    cout<<j<<" "<<k<<endl;
                    cout<<i<<" "<<k<<endl;
                    goto cont;
                }
            }
        }
        cont:;
    }
}