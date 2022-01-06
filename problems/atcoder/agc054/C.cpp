// created on 2021/6/27 by spacefarers
// problem: C - Roughly Sorted

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int nums[5005];
ll MOD=998244353;

int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    ll ans=1;
    for (int i=0;i<n;i++){
        int num_before=0;
        for (int j=0;j<i;j++){
            if (nums[j]>nums[i]) num_before++;
        }
        if (num_before==k){
            int new_ones=1;
            for (int j=i+1;j<n;j++){
                if (nums[j]>nums[i]) new_ones++;
                else break;
            }
            ans*=new_ones;
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}