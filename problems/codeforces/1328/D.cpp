// created on 2021/6/21 by spacefarers
// problem: D. Carousel

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

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
        vector<int> nums,ans(n,0);
        int k=2;
        bool need_cor=false;
        int segs=0,last=-1;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.push_back(a);
            if (last!=a) segs++;
            last=a;
        }
        if (segs%2&&nums.front()!=nums.back()){
            need_cor=true;
            k=3;
        }
        for (int i=0;i<n;i++){
            if (i!=0) ans[i]=(nums[i]==nums[i-1])?ans[i-1]:!ans[i-1];
            if (i!=0&&nums[i]==nums[i-1]&&need_cor){
                k=2;
                need_cor=false;
                ans[i]=!ans[i-1];
            }
        }
        for (int i=0;i<n;i++){
            if (nums[i]!=nums[0]) goto cont;
        }
        cout<<1<<endl;
        for (int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        continue;
        cont:;
        cout<<k<<endl;
        if (k==3) ans[n-1]=2;
        for (auto i:ans){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}