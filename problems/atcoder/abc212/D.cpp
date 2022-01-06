// created on 2021/7/31 by spacefarers
// problem: D - Querying Multiset

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
    int q;
    cin>>q;
    multiset<ll> nums;
    ll common_diff=0;
    for (int i=0;i<q;i++){
        int x;
        cin>>x;
        if (x==1){
            ll a;
            cin>>a;
            nums.insert(a-common_diff);
        } else if (x==2){
            ll a;
            cin>>a;
            common_diff+=a;
        } else {
            cout<<*(nums.begin())+common_diff<<endl;
            nums.erase(nums.begin());
        }
    }
}