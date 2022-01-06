// created on 2021/6/28 by spacefarers
// problem: C. Little Girl and Maximum Sum

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define ll long long
#define f first
#define s second

using namespace std;

int d[200005];

int main(){
    int n,q;
    cin>>n>>q;
    priority_queue<ll> qu,qu2;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        qu.push(a);
    }
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        d[a]++;
        d[b+1]--;
    }
    int c=0;
    for (int i=1;i<=n;i++){
        c+=d[i];
        qu2.push(c);
    }
    ll ans=0;
    while (!qu.empty()){
        ans+=qu.top()*qu2.top();
        qu.pop();
        qu2.pop();
    }
    cout<<ans<<endl;
}