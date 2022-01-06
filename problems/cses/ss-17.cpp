// created on 2021/6/29 by spacefarers
// problem: Sum of Three Values

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

pair<int,int> nums[5005];

int main(){
    int n,x;
    cin>>n>>x;
    for (int i=0;i<n;i++){
        cin>>nums[i].f;
        nums[i].s=i+1;
    }
    sort(nums,nums+n);
    for (int i=0;i<n;i++){
        int l=i+1,r=n-1;
        while (l<r){
            ll c_val=nums[i].f+nums[l].f+nums[r].f;
            if (c_val>x) r--;
            else if (c_val<x) l++;
            else {
                cout<<nums[i].s<<" "<<nums[r].s<<" "<<nums[l].s<<endl;
                exit(0);
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}