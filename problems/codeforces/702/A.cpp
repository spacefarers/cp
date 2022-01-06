#include <iostream>
#include <vector>

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
        int ans=0;
        for (int i=0;i<n-1;i++){
            int num1=min(nums[i], nums[i+1]), num2=max(nums[i], nums[i+1]);
            while (num1*2<num2){
                ans++;
                num1*=2;
            }
        }
        cout<<ans<<endl;
    }
}