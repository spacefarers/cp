// created on 2021/6/26 by spacefarers
// problem: A. Pretty Permutations

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for (int i=1;i<=n;i++){
            nums[i-1]=i;
        }
        for (int i=0;i<n-1;i+=2){
            swap(nums[i],nums[i+1]);
        }
        if (n%2) swap(nums[n-2],nums[n-1]);
        for (auto i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}