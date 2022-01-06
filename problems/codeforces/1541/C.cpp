// created on 2021/6/26 by spacefarers
// problem: C. Great Graphs

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll prefix[100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<ll> dists;
        for (int i=0;i<n;i++){
            ll a;
            cin>>a;
            dists.push_back(a);
        }
        sort(dists.begin(),dists.end());
        for (int i=0;i<n;i++){
            prefix[i]=dists[i];
            if (i!=0) prefix[i]+=prefix[i-1];
        }
        ll ans=0;
        for (int i=2;i<n;i++){
            ans+=(prefix[i-2]-(i-1)*dists[i]);
        }
        cout<<ans<<endl;
    }
}