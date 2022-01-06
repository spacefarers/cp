// created on 2021/6/25 by spacefarers
// problem: C. Stable Groups

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
    int n;
    ll k,x;
    cin>>n>>k>>x;
    vector<ll> nums;
    for (int i=0;i<n;i++){
        ll a;
        cin>>a;
        nums.push_back(a);
    }
    sort(nums.begin(),nums.end());
    multiset<ll> needed;
    for (int i=1;i<n;i++){
        ll gap=nums[i]-nums[i-1];
        if (gap==0) gap++;
        needed.insert((gap-1)/x);
    }
    int ans=n;
    for (auto i:needed){
        k-=i;
        if (k>=0) ans--;
        else break;
    }
    cout<<ans<<endl;
}