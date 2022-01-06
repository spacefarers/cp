// created on 2021/7/10 by spacefarers
// problem: Range Xor Queries

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int prefix[200005];

int main(){
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        prefix[i]=a^prefix[i-1];
    }
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<(prefix[b]^prefix[a-1])<<endl;
    }
}