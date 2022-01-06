#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        vector<int> nums;
        for (int j=0;j<x*2;j++){
            int a;
            cin>>a;
            nums.push_back(a);
        }
        sort(nums.begin(), nums.end());
        for (int j=0;j<x;j++){
            cout<<nums[j]<<" "<<nums[j+x]<<" ";
        }
        cout<<endl;
    }
}