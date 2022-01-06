#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,sum=0;
        cin>>n;
        vector<int> nums;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            sum+=a;
            nums.push_back(a);
        }
        if (sum%n){
            cout<<-1<<endl;
            continue;
        }
        sum/=n;
        int ans=0;
        for (auto i:nums){
            if (i>sum) ans++;
        }
        cout<<ans<<endl;
    }
}