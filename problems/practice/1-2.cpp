// created on 8/20/21 by spacefarers
// problem: #1858. [Scoi2010]序列操作

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

struct node {
    int pre0{},mid0{},suf0{};
    int pre1{},mid1{},suf1{};
    int s0{},s1{};
    bool tag=false;
    node operator+(const node &b){
        auto a=*this;
        node res;
        res.s0=a.s0+b.s0;
        res.s1=a.s1+b.s1;
        res.pre0=a.s1==0?a.s0+b.pre0:a.pre0;
        return res;
    }
};

int input[100000];
node tree[400000];

void propagate(node &p,node &l,node &r){
    if (p.s0==0){
        p.pre0=0;
        p.mid0=0;
        p.suf0=0;
    }
    if (p.s1==0){
        p.pre1=0;
        p.mid1=0;
        p.suf1=0;
    }
    if (p.tag){
    }
}

void build_tree(int s,int t,int p){
    if (s==t){
        if (input[s]==0){
            tree[p].s0=1;
            tree[p].pre0=1;
            tree[p].mid0=1;
            tree[p].suf0=1;
        } else {
            tree[p].s1=1;
            tree[p].pre1=1;
            tree[p].mid1=1;
            tree[p].suf1=1;
        }
        return;
    }
    int m=(t+s)/2;
    build_tree(s,m,p*2);
    build_tree(m+1,t,p*2+1);
    tree[p]=tree[p*2]+tree[p*2+1];
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>input[i];
    }
    build_tree(1,n,1);
    for (int i=0;i<m;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if (op==1){

        }
    }
}
