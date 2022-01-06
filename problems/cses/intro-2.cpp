#include <iostream>
#include <algorithm>

using namespace std;

int nums[200005];

int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        cin>>nums[i];
    }
    sort(nums+1, nums+n);
    for (int i=1;i<=n;i++){
        if (nums[i]!=i) {
            cout<<i<<endl;
            return 0;
        }
    }
}