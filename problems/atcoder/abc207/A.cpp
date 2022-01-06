// created on 2021/6/26 by spacefarers
// problem: A - Repression

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    vector<int> nums(3);
    for (int i=0;i<3;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    cout<<nums[1]+nums[2]<<endl;
}