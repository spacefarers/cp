// created on 2021/7/18 by spacefarers
// problem: B - Increasing Triples

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
    multiset<int> a,b,c;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        b.insert(x);
    }
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        c.insert(x);
    }
    int ans=0;
    for (auto i:a){
        auto itb=b.upper_bound(i);
        if (itb==b.end()) break;
        auto itc=c.upper_bound(*itb);
        if (itc==c.end()) break;
        ans++;
        b.erase(itb);
        c.erase(itc);
    }
    cout<<ans<<endl;
}