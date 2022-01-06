#include <iostream>

using namespace std;

#define ll long long
#define MAXN 100005

ll tree[4*MAXN],lazy_add[4*MAXN],lazy_mul[4*MAXN],input[MAXN],MOD;

void modding(int p){
    tree[p]%=MOD;
    lazy_add[p]%=MOD;
    lazy_mul[p]%=MOD;
    if (p*2+1<=4*MAXN){
        tree[p*2]%=MOD;
        tree[p*2+1]%=MOD;
        lazy_add[p*2]%=MOD;
        lazy_add[p*2+1]%=MOD;
        lazy_mul[p*2]%=MOD;
        lazy_mul[p*2+1]%=MOD;
    }
}

void build_tree(int s,int t,int p){
    lazy_mul[p]=1;
    if (s==t){
        tree[p]=input[s];
        return;
    }
    int m=(t+s)/2;
    build_tree(s,m,p*2);
    build_tree(m+1,t,p*2+1);
    modding(p);
    tree[p]=tree[p*2]+tree[p*2+1];
}

void propagate(int p,int s,int t){
    int m=(s+t)/2;
    if (lazy_mul[p]!=1){
        tree[p*2]*=lazy_mul[p],tree[p*2+1]*=lazy_mul[p];
        lazy_mul[p*2]*=lazy_mul[p];
        lazy_mul[p*2+1]*=lazy_mul[p];
        lazy_add[p*2]*=lazy_mul[p];
        lazy_add[p*2+1]*=lazy_mul[p];
        lazy_mul[p]=1;
        modding(p);
    }
    if (lazy_add[p]){
        tree[p*2]+=lazy_add[p]*(m-s+1),tree[p*2+1]+=lazy_add[p]*(t-m);
        lazy_add[p*2]+=lazy_add[p];
        lazy_add[p*2+1]+=lazy_add[p];
        lazy_add[p]=0;
        modding(p);
    }
}

void update_tree(int s,int t,int p,int l,int r,ll c, bool add){
    if (l<=s&&t<=r){
        if (add){
            tree[p]+=(t-s+1)*c;
            lazy_add[p]+=c;
        } else {
            tree[p]*=c;
            lazy_mul[p]*=c;
            lazy_add[p]*=c;
        }
        modding(p);
        return;
    }
    int m=(t+s)/2;
    propagate(p,s,t);
    if (l<=m) update_tree(s,m,p*2,l,r,c,add);
    if (r>m) update_tree(m+1,t,p*2+1,l,r,c,add);
    modding(p);
    tree[p]=tree[p*2]+tree[p*2+1];
}

ll get_sum(int s,int t,int p,int l,int r){
    if (l<=s&&t<=r) return tree[p];
    int m=(t+s)/2;
    ll sum=0;
    propagate(p,s,t);
    if (l<=m) sum+=get_sum(s,m,p*2,l,r);
    sum%=MOD;
    if (r>m) sum+=get_sum(m+1,t,p*2+1,l,r);
    return sum%MOD;
}

int main(){
    // 线段树模板
    int n,m;
    cin>>n>>m>>MOD;
    for (int i=1;i<=n;i++){
        cin>>input[i];
    }
    build_tree(1,n,1);
    for (int i=1;i<=m;i++){
        int a;
        cin>>a;
        if (a==1){
            int b,c;
            ll d;
            cin>>b>>c>>d;
            update_tree(1,n,1,b,c,d,false);
        } else if (a==2){
            int b,c;
            ll d;
            cin>>b>>c>>d;
            update_tree(1,n,1,b,c,d,true);
        } else {
            int b, c;
            cin>>b>>c;
            cout<<get_sum(1,n,1,b,c)<<endl;
        }
    }
//    cout<<get_sum(1,n,1,1,10)<<endl;
}