// created on 2021/7/17 by spacefarers
// problem: A. Binary Decimal

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        string n;
        cin>>n;
        int ans=0;
        for (int i=0;i<n.size();i++){
            ans=max(ans,stoi(n.substr(i,1)));
        }
        cout<<ans<<endl;
    }
}