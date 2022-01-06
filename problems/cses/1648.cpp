// created on 2021/7/1 by spacefarers
// problem: Dynamic Range Sum Queries

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll tree[200005];
int n;
void add(ll k,ll x){
    while (k<=n){
        tree[k]+=x;
        k+=k&-k;
    }
}

ll get_sum(ll k){
    ll ans=0;
    while (k>0){
        ans+=tree[k];
        k-=k&-k;
    }
    return ans;
}

int main(){
    int q;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        add(i+1,a);
    }
    for (int i=0;i<q;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if (a==1){
            ll prev=get_sum(b)-get_sum(b-1);
            add(b,c-prev);
        } else {
            cout<<get_sum(c)-get_sum(b-1)<<endl;
        }
    }
}