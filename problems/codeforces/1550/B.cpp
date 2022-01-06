// created on 2021/7/14 by spacefarers
// problem: B. Maximum Cost Deletion

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
        int n,a,b;
        string x;
        cin>>n>>a>>b>>x;
        int ans=a*n;
        if (b>=0){
            ans+=n*b;
        } else {
            int ones=0,zeros=0;
            for (int i=0;i<n;){
                if (x[i]=='1'){
                    ones++;
                    while (x[i]=='1') i++;
                } else {
                    zeros++;
                    while (x[i]=='0') i++;
                }
            }
            ans+=(min(ones,zeros)+1)*b;
        }
        cout<<ans<<endl;
    }
}