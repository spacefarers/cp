// created on 2021/6/30 by spacefarers
// problem: 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first

using namespace std;

int maxArea(vector<int>& height) {
    int n=(int)height.size();
    int l=0,r=n-1,ans=0;
    while (l<r){
        ans=max(ans,min(height[r],height[l])*(r-l));
        if (height[r]>height[l]) l++;
        else r--;
    }
    return ans;
}

int main(){
    vector<int> input={2,1};
    cout<<maxArea(input)<<endl;
}