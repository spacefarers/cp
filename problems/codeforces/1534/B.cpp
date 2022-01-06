// created on 2021/6/14 by spacefarers
// problem: 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll nums[400005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        ll ans=0;
        cin>>n;
        memset(nums,0,sizeof nums);
        for (int i=1;i<=n;i++){
            cin>>nums[i];
            ans+=abs(nums[i]-nums[i-1]);
        }
        ans+=nums[n];
        for (int i=1;i<=n;i++){
            ll target=max(nums[i-1],nums[i+1]);
            if (nums[i]>target){
                ans-=nums[i]-target;
            }
        }
        cout<<ans<<endl;
    }
}