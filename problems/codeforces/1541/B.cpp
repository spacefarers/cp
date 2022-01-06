// created on 2021/6/26 by spacefarers
// problem: B. Pleasant Pairs

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;


int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int ans=0;
        vector<pair<int,int>> nums;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.emplace_back(a,i+1);
        }
        sort(nums.begin(),nums.end());
        int bound=n-1;
        for (int i=0;i<n;i++){
            while (nums[i].f*nums[bound].f>=n*2) bound--;
            if (bound<=i) break;
            for (int j=i+1;j<=bound;j++){
                if (nums[i].f*nums[j].f==nums[i].s+nums[j].s) ans++;
            }
        }
        cout<<ans<<endl;
    }
}