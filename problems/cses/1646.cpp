// created on 2021/7/1 by spacefarers
// problem: Static Range Sum Queries

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll prefix[200005];

int main(){
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>prefix[i];
        prefix[i]+=prefix[i-1];
    }
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<endl;
    }
}