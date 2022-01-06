// created on 8/28/21 by spacefarers
// problem: P3384 【模板】轻重链剖分/树链剖分

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

struct SegTree{
    vector<ll> tree,lazy,*inputs;
    int n;
    explicit SegTree(vector<ll> *inputs):inputs(inputs){
        n=(int)inputs->size();
        tree.reserve(inputs->size()*4+1);
        lazy.reserve(inputs->size()*4+1);
        build_tree();
    }
    void build_tree(int v=1, int tl=1, int tr=-1){
        if (tr==-1) tr=n;
        if (tl==tr){
            tree[v]=(*inputs)[tl-1];
        } else {
            int tm=(tl+tr)/2;
            build_tree(v*2, tl, tm);
            build_tree(v*2+1, tm+1, tr);
            tree[v]=tree[v*2]+tree[v*2+1];
        }
    }

    void propagate(int v,int tl,int tr,int m){
        tree[v*2]+=lazy[v]*(m-tl+1),tree[v*2+1]+=lazy[v]*(tr-m);
        lazy[v*2]+=lazy[v];
        lazy[v*2+1]+=lazy[v];
        lazy[v]=0;
    }

    void update_tree(int l,int r,ll c,int v=1,int tl=1,int tr=-1){
        if (tr==-1) tr=n;
        if (l<=tl&&tr<=r){
            tree[v]+=(tr-tl+1)*c;
            lazy[v]+=c;
            return;
        }
        int m=(tr+tl)/2;
        if (lazy[v]&&tl!=tr) propagate(v,tl,tr,m);
        if (l<=m) update_tree(l,r,c,v*2,tl,m);
        if (r>m) update_tree(l,r,c,v*2+1,m+1,tr);
        tree[v]=tree[v*2]+tree[v*2+1];
    }

    ll get_sum(int l,int r,int v=1,int tl=1,int tr=-1){
        if (tr==-1) tr=n;
        if (l<=tl&&tr<=r) return tree[v];
        int m=(tr+tl)/2;
        ll ans=0;
        if (lazy[v]) propagate(v,tl,tr,m);
        if (l<=m) ans+=get_sum(l,r,v*2,tl,m);
        if (r>m) ans+=get_sum(l,r,v*2+1,m+1,tr);
        return ans;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> inputs;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        inputs.push_back(a);
    }
    SegTree T(&inputs);
    for (int i=0;i<m;i++){
        int a,x,y;
        cin>>a>>x>>y;
        if (a==1){
            int k;
            cin>>k;
            T.update_tree(x,y,k);
        } else {
            cout<<T.get_sum(x,y)<<endl;
        }
    }
}
