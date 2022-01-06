// created on 6/18/21 by spacefarers
// problem: A. Arithmetic Array

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
        int sum=0;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            sum+=a;
        }
        if (sum<n) cout<<1<<endl;
        else if (sum==n) cout<<0<<endl;
        else {
            cout<<sum-n<<endl;
        }
    }
}