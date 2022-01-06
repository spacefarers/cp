#include <iostream>
#include <vector>

using namespace std;

int nums[200005];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        nums[a]=i;
    }
    int ans=1;
    for (int i=2;i<=n;i++){
        if (nums[i-1]>nums[i]) ans++;
    }
    cout<<ans<<endl;
}