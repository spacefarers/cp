// created on 2021/6/14 by spacefarers
// problem: C. Sequence Pair Weight

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

int nums[100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        map<pair<ll,ll>,pair<ll,ll>> mp;
        map<ll,ll> cnt;
        for (int i=1;i<=n;i++){
            cin>>nums[i];
            cnt[nums[i]]++;
            mp[{nums[i],cnt[nums[i]]}]={i+(cnt[nums[i]]==1?0:mp[{nums[i],cnt[nums[i]]-1}].f),n-i+1};
        }
        ll ans=0;
        for (auto i:mp){
            if (i.f.s<=1) continue;
            ans+=mp[{i.f.f,i.f.s-1}].f*i.s.s;
        }
        cout<<ans<<endl;
    }
}