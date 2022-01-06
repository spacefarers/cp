#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int nums[100005], max_nums[100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(nums, 0, sizeof nums);
        int n;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>nums[i];
        }
        int max_pos=0;
        for (int i=0;i<n;i++){
            if (nums[i]>nums[max_pos]) max_pos=i;
            max_nums[i]=max_pos;
        }
        int pos=n, last_pos=n;
        vector<int> ans;
        do {
            pos=max_nums[pos-1];
            for (int i=pos;i<last_pos;i++){
                ans.push_back(nums[i]);
            }
            last_pos=pos;
        } while (pos>0);
        for (auto &i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}