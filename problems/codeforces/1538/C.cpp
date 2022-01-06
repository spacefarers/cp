#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> nums;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.push_back(a);
        }
        sort(nums.begin(),nums.end());
        int left_p=n-1,right_p=n-1;
        long long ans=0;
        for (int i=0;i<n;i++){
            while (left_p>=0&&nums[i]+nums[left_p]>=l) left_p--;
            while (right_p>=0&&nums[i]+nums[right_p]>r) right_p--;
            ans+=max(right_p,i)-max(left_p,i);
        }
        cout<<ans<<endl;
    }
}