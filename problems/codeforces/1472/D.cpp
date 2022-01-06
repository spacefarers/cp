#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for (int i=0;i<n;++i){
            cin>>nums[i];
        }
        sort(nums.begin(), nums.end(), greater<int>());
        long long a=0, b=0;
        bool alice=true;
        for (auto &i:nums){
            if (alice&&i%2==0) a+=i;
            else if (!alice&&i%2==1) b+=i;
            alice=!alice;
        }
        if (a>b) cout<<"Alice"<<endl;
        else if (a==b) cout<<"Tie"<<endl;
        else cout<<"Bob"<<endl;
    }
}