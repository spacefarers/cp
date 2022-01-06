#include <iostream>

using namespace std;

int n;
int tree[200005], inputs[100005];

void build_tree(int v=1, int tl=0, int tr=n-1){
    if (tl==tr){
        tree[v]=inputs[tl]; // We are at the end of the tree where the range is 1, corresponding to the inputs
    } else {
        int tm=(tl+tr)/2;
        build_tree(v*2, tl, tm); // we are recursively calling to build up the tree
        build_tree(v*2+1, tm+1, tr);
        tree[v]=tree[v*2]+tree[v*2+1]; // Where we combind our previous results
    }
}

int sum(int a, int b){
    a+=n;b+=n;
    int s=0;
    while (a<=b){
        if (a%2==1) s+=tree[a++];
        if (b%2==0) s+=tree[b--];
        a/=2;b/=2;
    }
    return s;
}

void add(int k, int x){
    k+=n;
    tree[k]+=x;
    for (k/=2;k>=1;k/=2){
        tree[k]=tree[2*k]+tree[2*k+1];
    }
}

int main(){
    cin>>n;
    for (int i=0;i<n;++i) cin>>inputs[i];

}