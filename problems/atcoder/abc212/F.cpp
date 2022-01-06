// created on 2021/7/31 by spacefarers
// problem: F - Greedy Takahashi

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;

set<pair<int,int>> node[1000005];
int link[100005];

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<pair<int,int>,pair<int,int>>> paths;
    for (int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        node[a].insert({c,i});
        paths.push_back({{a,b},{c,d}});
    }
    for (int i=0;i<m;i++){
        link[i]=-1;
        auto it=node[paths[i].f.s].lower_bound({paths[i].s.s,-1e9});
        if (it!=node[paths[i].f.s].end()) link[i]=it->s;
    }
    for (int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        auto it=node[b].lower_bound({a,-1e9});
        if (it==node[b].end()) cout<<b<<endl;
        else {
            int id=it->s;
            int city=paths[id].f.f;
            while (true){
                if (id==-1||c<=paths[id].s.f){
                    cout<<city<<endl;
                    break;
                }
                city=paths[id].f.s;
                if (paths[id].s.s>=c){
                    cout<<paths[id].f.f<<" "<<paths[id].f.s<<endl;
                    break;
                }
                id=link[id];
            }
        }
    }
}