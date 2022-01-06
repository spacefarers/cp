// created on 2021/7/17 by spacefarers
// problem: C. Pursuit

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll tree1[100005],tree2[100005];
int n;

void add(int k,int x,ll *tree){
    while (k<=n){
        tree[k]+=x;
        k+=k&-k;
    }
}

ll sum(int k,const ll tree[100005]){
    ll ans=0;
    if (k>n) k=n;
    while (k>0){
        ans+=tree[k];
        k-=k&-k;
    }
    return ans;
}

bool validate(int x){
    int nums_take=x-x/4;
    int hundreds=min(nums_take,x-n);
    ll your_money=hundreds*100;
    your_money+=sum(nums_take-hundreds,tree1);
    ll llyas_money=sum(nums_take,tree2);
    return your_money<llyas_money;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(tree1,0,sizeof tree1);
        memset(tree2,0,sizeof tree2);
        cin>>n;
        vector<int> yours,llyas;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            yours.push_back(a);
        }
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            llyas.push_back(a);
        }
        sort(yours.begin(),yours.end(),greater<>());
        sort(llyas.begin(),llyas.end(),greater<>());
        for (int i=1;i<=n;i++){
            add(i,yours[i-1],tree1);
        }
        for (int i=1;i<=n;i++){
            add(i,llyas[i-1],tree2);
        }
        int z=n-1;
        for (int i=1e7;i>=1;i/=2){
            while (validate(z+i)) z+=i;
        }
        z-=n-1;
        cout<<z<<endl;
    }
}