#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int tree[100005], inputs[100005];

void build_tree(int node, int start, int end){
    if (start==end) tree[node]=inputs[start];
    else {
        int mid=(start+end)/2;
        build_tree(2*node, start, mid);
        build_tree(2*node+1, mid+1, end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update_tree(int node, int start, int end, int idx, int val){
    if (start==end){
        inputs[idx]+=val;
        tree[node]=val;
    } else {
        int mid=(start+end)/2;
        if (start<=idx and idx<=mid){
            update_tree(2*node, start, mid, idx, val);
        } else {
            update_tree(2*node+1, mid+1, end, idx, val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r){
    if (l>r) return 0;
    if (l==start and r==end) return tree[node];
    int mid=(start+end)/2;
    int p1=query(2*node, start, mid, l, min(r, mid));
    int p2=query(2*node+1, mid+1, end, max(l, mid+1), r);
    return p1+p2;
}

int main() {
//    setIO("");
    int n, q;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>inputs[i];
    }

    return 0;
}