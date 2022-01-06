#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;

int main(){
    for (int i=0;i<7;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    int last=nums[2];
    if (nums[0]+nums[1]==nums[2]){
        last=nums[3];
    }
    cout<<nums[0]<<" "<<nums[1]<<" "<<last<<endl;
}