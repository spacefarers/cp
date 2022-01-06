// created on 2021/7/9 by spacefarers
// problem: B. Customising the Track

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
        ll sum=0;
        for (int i=0;i<n;i++){
            ll a;
            cin>>a;
            sum+=a;
        }
        ll left=sum%n;
        cout<<left*(n-left)<<endl;
    }
}