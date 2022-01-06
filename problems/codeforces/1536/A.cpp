#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int,bool> hit;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> nums;
        hit.clear();
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.push_back(a);
            hit[a]=true;
        }
        bool ok=false;
        while (n<=300){
            int extra=0;
            sort(nums.begin(),nums.end());
            for (int i=0;i<n;i++){
                for (int j=i+1;j<n;j++){
                    if (hit[nums[j]-nums[i]]) continue;
                    nums.push_back(nums[j]-nums[i]);
                    hit[nums[j]-nums[i]]=true;
                    extra++;
                }
            }
            n+=extra;
            if (extra==0){
                ok=true;
                break;
            }
        }
        if (ok){
            cout<<"YES"<<endl;
            cout<<n<<endl;
            for (auto i:nums){
                cout<<i<<" ";
            }
            cout<<endl;
        } else cout<<"NO"<<endl;
    }
}