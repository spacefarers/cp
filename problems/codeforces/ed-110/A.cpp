#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        vector<int> nums;
        for (int i=0;i<4;i++){
            int a;
            cin>>a;
            nums.push_back(a);
        }
        int a=max(nums[0],nums[1]),b=max(nums[2],nums[3]);
        if (b>a) swap(a,b);
        sort(nums.begin(),nums.end());
        if (a==nums[3]&&b==nums[2]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}