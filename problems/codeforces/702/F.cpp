#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long
#define f first
#define s second

ll n, sums[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(sums, 0, sizeof sums);
        cin>>n;
        map<ll, ll> mp;
        for (int i=0;i<n;i++){
            ll a;
            cin>>a;
            mp[a]++;
        }
        vector<ll> nums;
        nums.reserve(mp.size());
        vector<ll> check_all;
        for (auto &i:mp){
            nums.push_back(i.second);
        }
        sort(nums.begin(), nums.end(), greater<ll>());
        for (ll i=(ll)nums.size()-1;i>=0;i--){
            sums[i]=sums[i+1]+nums[i];
        }
        ll prev=0x7fffffff, counts=0, c_total=0, ans=0x7fffffff;
        for (int i=0;i<nums.size();i++){
            c_total+=(prev-nums[i])*counts;
            ll c_ans=sums[i+1];
            c_ans+=c_total;
            counts++;
            prev=nums[i];
            ans=min(ans, c_ans);
        }
        cout<<ans<<endl;
    }
}