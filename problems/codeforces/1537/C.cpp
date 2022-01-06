// created on 6/18/21 by spacefarers
// problem: C. Challenging Cliffs

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
        vector<int> nums;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.push_back(a);
        }
        sort(nums.begin(),nums.end(),greater<>());
        int min_diff=1e9;
        for (int i=0;i<n-1;i++){
            min_diff=min(min_diff,nums[i]-nums[i+1]);
        }
        int hit=-1;
        for (int i=0;i<n-1;i++){
            if (nums[i]-nums[i+1]==min_diff){
                hit=i;
            }
        }
        cout<<nums[hit+1]<<" ";
        for (int i=hit-1;i>=0;i--){
            cout<<nums[i]<<" ";
        }
        for (int i=n-1;i>hit+1;i--){
            cout<<nums[i]<<" ";
        }
        cout<<nums[hit]<<endl;
    }
}