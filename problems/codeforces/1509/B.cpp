#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n,tree[100005];

void add(int k,int x){
    while (k<=n){
        tree[k]+=x;
        k+=k&-k;
    }
}

int get_sum(int k){
    int ans=0;
    while (k>0){
        ans+=tree[k];
        k-=k&-k;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        string a;
        cin>>n>>a;
        int ms=0;
        for (int i=0;i<n;i++){
            if (a[i]=='M') ms++;
        }
        if (ms*3!=n){
            cout<<"NO"<<endl;
            continue;
        }
        for (int _=0;_<2;_++){
            memset(tree,0,sizeof tree);
            for (int i=0;i<n;i++){
                if (a[i]=='T') add(i+1,1);
                else{
                    if (get_sum(i+1)<1){
                        cout<<"NO"<<endl;
                        goto cont;
                    }
                    add(i+1,-1);
                }
            }
            reverse(a.begin(),a.end());
        }
        cout<<"YES"<<endl;
        cont:;
    }
}