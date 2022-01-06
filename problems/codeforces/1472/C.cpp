#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[200005], nums[200005], score[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        memset(dp, 0, sizeof dp);
        memset(nums, 0, sizeof nums);
        for (int i=0;i<n;++i){
            cin>>nums[i];
            score[i]=nums[i];
        }
        for (int i=n-1;i>=0;--i){
            if (i+nums[i]<n) score[i]+=score[i+nums[i]];
        }
        cout<<*max_element(score, score+n)<<endl;
    }
}