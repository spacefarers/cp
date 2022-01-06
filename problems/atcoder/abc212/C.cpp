// created on 2021/7/31 by spacefarers
// problem: C - Min Difference

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1,arr2;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        arr1.push_back(a);
    }
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        arr2.push_back(a);
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    int ind=0,ans=2e9;
    for (auto i:arr1){
        int closest=abs(arr2[ind]-i);
        if (ind<m-1){
            while (ind<m-1&&abs(arr2[ind+1]-i)<=closest){
                closest=abs(arr2[ind+1]-i);
                ind++;
            }
        }
        ans=min(ans,closest);
    }
    cout<<ans<<endl;
}