// created on 2021/7/15 by spacefarers
// problem: A - Maximum Sum on Even Positions

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll diff[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(diff,0,sizeof diff);
        ll n;
        cin>>n;
        ll ans=0;
        for (int i=0;i<n;i++){
            ll a;
            cin>>a;
            if (i%2){
                diff[i]+=a;
            } else {
                diff[i]-=a;
                ans+=a;
            }
            if (i!=0) diff[i]+=diff[i-1];
        }
        ll max_diff=0,lowest_even=0,lowest_odd=0;
        for (int i=0;i<n;i++){
            ll lowest=(i%2)?lowest_odd:lowest_even;
            max_diff=max(max_diff,diff[i]-lowest);
            if (i%2){
                lowest_odd=min(lowest_odd,diff[i]);
            } else {
                lowest_even=min(lowest_even,diff[i]);
            }
        }
        cout<<ans+max_diff<<endl;
    }
}