#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int double_nums=0;
        vector<int> nums;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            if (a%2) nums.push_back(a);
            else double_nums++;
        }
        int ans=0;
        for (int i=n-double_nums;i<n;i++){
            ans+=i;
        }
        for (int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                if (gcd(nums[i],nums[j])>1) ans++;
            }
        }
        cout<<ans<<endl;
    }
}