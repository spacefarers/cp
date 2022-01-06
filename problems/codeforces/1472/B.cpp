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
        vector<int> nums;
        for (int i=0;i<n;++i){
            int a;
            cin>>a;
            nums.push_back(a);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int a=0, b=0;
        for (auto &item:nums){
            if (a>b) b+=item;
            else a+=item;
        }
        cout<<((a==b)?"YES":"NO")<<endl;
    }
}