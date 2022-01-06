#include <iostream>
#include <vector>

using namespace std;

long long sums[100005], nums[100005];

int main(){
    long long n, q, k;
    cin>>n>>q>>k;
    for (int i=0;i<n;i++) cin>>nums[i];
    for (int i=1;i<n-1;i++){
        sums[i]=sums[i-1]+nums[i+1]-nums[i-1]-2;
    }
    for (int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;
        a--;b--;
        if (a==b){ // handle the case where there is only one number
            cout<<k-1<<endl;
            continue;
        }
        long long mid=sums[b-1]-sums[a];
        cout<<mid+nums[a+1]-0-2+(k+1)-nums[b-1]-2<<endl;
    }
}