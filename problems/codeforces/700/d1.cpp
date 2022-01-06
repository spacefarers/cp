#include <iostream>
#include <vector>

using namespace std;

int a[100005];
bool used[100005];

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> nums;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (nums.empty()||nums.back().first!=a[i]) nums.emplace_back(a[i], 1);
        else nums.back().second++;
    }
    int ans=0, t=-1, last=-2;
    for (int i=0;i<nums.size();i++){
        if ((t<0||i==nums.size()-1||nums[t].first!=nums[i+1].first||nums[i].second>1)&&nums[i].first!=last) {
            nums[i].second--;
            ans++;
            last=nums[i].first;
        }
        if (nums[i].second>0) t=i;
    }
    for (auto &i:nums){
        if (i.second!=0) ans++;
    }
    cout<<ans<<endl;
}