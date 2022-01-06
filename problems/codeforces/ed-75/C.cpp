#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        vector<int> even_nums, odd_nums;
        for (auto &j:a){
            if ((j-'0')%2) odd_nums.push_back(j-'0');
            else even_nums.push_back(j-'0');
        }
        int cur=0;
        string ans;
        for (int j=0;j<even_nums.size();j++){
            if (cur>=odd_nums.size()||odd_nums[cur]>even_nums[j]){
                ans+=to_string(even_nums[j]);
            } else {
                j--;
                ans+=to_string(odd_nums[cur++]);
            }
        }
        for (int j=cur;j<odd_nums.size();j++){
            ans+=to_string(odd_nums[j]);
        }
        cout<<ans<<endl;
    }
}