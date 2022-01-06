// created on 2021/7/1 by spacefarers
// problem: Dynamic Range Minimum Queries
// Min Segment Tree Template
// 最小值线段书模板

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll tree[800005],inputs[200005],lazy[800005];
int n;

void build_tree(int v=1, int tl=1, int tr=n){
    if (tl==tr){
        tree[v]=inputs[tl];
    } else {
        int tm=(tl+tr)/2;
        build_tree(v*2, tl, tm);
        build_tree(v*2+1, tm+1, tr);
        tree[v]=min(tree[v*2],tree[v*2+1]);
    }
}

void propagate(int v,int tl,int tr,int m){
    tree[v*2]=lazy[v],tree[v*2+1]=lazy[v];
    lazy[v*2]=lazy[v];
    lazy[v*2+1]=lazy[v];
    lazy[v]=0;
}

void update_tree(int l,int r,ll c,int v=1,int tl=1,int tr=n){
    if (l<=tl&&tr<=r){
        tree[v]=c;
        lazy[v]=c;
        return;
    }
    int m=(tr+tl)/2;
    if (lazy[v]&&tl!=tr) propagate(v,tl,tr,m);
    if (l<=m) update_tree(l,r,c,v*2,tl,m);
    if (r>m) update_tree(l,r,c,v*2+1,m+1,tr);
    tree[v]=min(tree[v*2],tree[v*2+1]);
}

ll get_min(int l,int r,int v=1,int tl=1,int tr=n){
    if (l<=tl&&tr<=r) return tree[v];
    int m=(tr+tl)/2;
    ll ans=1e9;
    if (lazy[v]) propagate(v,tl,tr,m);
    if (l<=m) ans=min(ans,get_min(l,r,v*2,tl,m));
    if (r>m) ans=min(ans,get_min(l,r,v*2+1,m+1,tr));
    return ans;
}

int main(){
    int q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>inputs[i];
    }
    build_tree();
    for (int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if (a==1){
            update_tree(b,b,c);
        } else {
            cout<<get_min(b,c)<<endl;
        }
    }
}