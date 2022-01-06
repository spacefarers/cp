#include <iostream>

using namespace std;

int nums[200005];
int sums[200005], min_sums[200005];
int n, k;

bool validate(int x){
    int sum=0, min_sum=0x7fffffff;
    for (int i=0;i<n;i++){
        sum+=nums[i]>=x?1:-1;
        sums[i]=sum;
        min_sum=min(sum, min_sum);
        min_sums[i]=min_sum;
    }
    int mx=sums[k-1], mn=0;
    for (int i=k;i<n;i++){
        mn=min(mn, sums[i-k]);
        mx=max(mx, sums[i]-mn);
    }
    return mx>0;
}

int main(){
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    int z=0;
    for (int i=n;i>=1;i/=2){
        while (validate(z+i)) z+=i;
    }
    cout<<z<<endl;
}