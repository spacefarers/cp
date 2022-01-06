// created on 2021/6/23 by spacefarers
// problem: Problem 3. Fenced In
// Incomplete, modified MST

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;
vector<pair<int,pair<int,int>>> paths;

int main(){
    ll a,b,n,m;
    cin>>a>>b>>n>>m;
    vector<int> vert,hori;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
//        if (i>0) vert.back()=x-vert.back();
        vert.push_back(x);
    }
    for (int i=0;i<m;i++){
        int x;
        cin>>x;
//        if (i>0) hori.back()=x-hori.back();
        hori.push_back(x);
    }
    sort(vert.begin(),vert.end());
    sort(hori.begin(),hori.end());
    for (int i=0;i<n-1;i++){
        vert[i]=vert[i+1]-vert[i];
    }
    for (int i=0;i<m-1;i++){
        hori[i]=hori[i+1]-hori[i];
    }
    vert.pop_back(),hori.pop_back();
    sort(vert.begin(),vert.end());
    sort(hori.begin(),hori.end());
    ll ans=0;
    int vi=0,hi=0;
    for (int i=0;i<n+m-2;i++){
        if (vert[vi]*(m-hi)<hori[hi]*(n-vi)&&vi<n-1){
            ans+=vert[vi++]*(m-hi);
        } else {
            ans+=hori[hi++]*(n-vi);
        }
    }
    cout<<ans<<endl;
}