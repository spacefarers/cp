#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n, d;
        cin>>n>>d;
        bool ok=true;
        vector<int> nums(n);
        for (int i=0;i<n;i++){
            cin>>nums[i];
            if (nums[i]>d) ok=false;
        }
        sort(nums.begin(), nums.end());
        if (nums[0]+nums[1]<=d||ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}