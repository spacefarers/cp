#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long

ll sums[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(sums, 0, sizeof sums);
        int n;
        cin>>n;
        vector<ll> nums;
        map<ll, vector<ll>> mp;
        for (int i=0;i<n;i++){
            ll a;
            cin>>a;
            nums.push_back(a);
            mp[a].push_back(i);
        }
        sort(nums.begin(), nums.end());
        sums[0]=nums[0];
        for (int i=1;i<n;i++){
            sums[i]=sums[i-1]+nums[i];
        }
        int cutting_point=-1;
        for (int i=0;i<n-1;i++){
            if (sums[i]<nums[i+1]) cutting_point=nums[i+1];
        }
        vector<int> ans;
        for (int i=0;i<n;i++){
            if (nums[i]>=cutting_point){
                for (auto &j:mp[nums[i]]){
                    ans.push_back(j);
                }
                mp[nums[i]].clear();
            }
        }
        sort(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for (auto &i:ans){
           cout<<i+1<<" ";
        }
        cout<<endl;
    }
}