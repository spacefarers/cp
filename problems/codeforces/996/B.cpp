// created on 2021/6/27 by spacefarers
// problem: B. World Cup

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n;
    cin>>n;
    set<pair<ll,ll>> st;
    for (int i=0;i<n;i++){
        ll a;
        cin>>a;
        st.insert({a,i});
    }
    pair<ll,ll> ans={1e13,-1};
    for (auto i:st){
        ll pos=i.f%n;
        ll time=i.f;
        if (pos>i.s) time+=n-pos+i.s;
        else time+=i.s-pos;
        if (time<ans.f) ans={time,i.s};
    }
    cout<<ans.s+1<<endl;
}