// created on 2021/7/1 by spacefarers
// problem: D. Captain Flint and Treasure

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

#define ll long long
#define f first
#define s second

using namespace std;

ll a[200005],w[200005];
int deg[200005],b[200005];
vector<int> p[200005];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        w[i]=a[i];
    }
    for (int i=0;i<n;i++){
        cin>>b[i];
        if (b[i]!=-1)
            deg[--b[i]]++;
    }
    stack<int> st;
    for (int i=0;i<n;i++){
        if (deg[i]==0) st.push(i);
    }
    while (!st.empty()){
        int u=st.top();
        st.pop();
        if (b[u]!=-1){
            if (a[u]>=0){
                a[b[u]]+=a[u];
                p[u].push_back(b[u]);
            } else p[b[u]].push_back(u);
            if (--deg[b[u]]==0) st.push(b[u]);
        }
    }
    memset(deg,0,sizeof deg);
    for (int i=0;i<n;i++){
        for (auto j:p[i]){
            deg[j]++;
        }
    }
    for (int i=0;i<n;i++){
        if (deg[i]==0) st.push(i);
    }
    ll ans=0;
    vector<int> order;
    while (!st.empty()){
        int u=st.top();
        st.pop();
        ans+=w[u];
        order.push_back(u);
        w[b[u]]+=w[u];
        for (auto i:p[u]){
            if (--deg[i]==0) st.push(i);
        }
    }
    cout<<ans<<endl;
    for (auto i:order){
        cout<<i+1<<" ";
    }
}