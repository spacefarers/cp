// created on 2021/7/5 by spacefarers
// problem: D. Multiset
// Order Statistic Tree

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int tree[1000005],n;

void add(int k,int x){
    while (k<=n+1){
        tree[k]+=x;
        k+=k&-k;
    }
}

int sum(int k){
    int ans=0;
    while (k>0){
        ans+=tree[k];
        k-=k&-k;
    }
    return ans;
}

void remove_kth(int k){
    int z=0;
    for (int i=n;i>=1;i/=2){
        while (z+i<=n&&sum(z+i)<k) z+=i;
    }
    z++;
    add(z,-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        add(a,1);
    }
    for (int i=0;i<q;i++){
        int a;
        cin>>a;
        if (a<0){
            remove_kth(-a);
        } else {
            add(a,1);
        }
    }
    int z=0;
    for (int i=n;i>=1;i/=2){
        while (z+i<=n&&sum(z+i)<1) z+=i;
    }
    if (z<n) z++;
    else z=0;
    cout<<z<<endl;
}