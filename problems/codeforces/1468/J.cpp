// created on 2021/7/7 by spacefarers
// problem: J. Road Reform

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int father[200005];

int find(int x){
    if (father[x]!=x) father[x]=find(father[x]);
    return father[x];
}

void unionn(int a,int b){
    int c=find(a),d=find(b);
    father[c]=d;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m,k;
        cin>>n>>m>>k;
        for (int i=0;i<=n;i++){
            father[i]=i;
        }
        vector<pair<int,pair<int,int>>> roads;
        pair<int,pair<int,int>> best_rd={1e9,{0,0}};
        for (int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if (c<k&&(k-c<best_rd.f)){
                roads.push_back(best_rd);
                best_rd={c,{a,b}};
            } else roads.push_back({c,{a,b}});
        }
        unionn(best_rd.s.f,best_rd.s.s);
        sort(roads.begin(),roads.end());
        bool need_makeup=true;
        int ans=0;
        for (auto i:roads){
            if (find(i.s.f)==find(i.s.s)) continue;
            unionn(i.s.f,i.s.s);
            if (i.f>=k){
                need_makeup=false;
                ans+=i.f-k;
            }
        }
        if (need_makeup){
            ans+=k-best_rd.f;
        }
        cout<<ans<<endl;
    }
}