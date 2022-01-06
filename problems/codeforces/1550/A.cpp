// created on 2021/7/14 by spacefarers
// problem: A. Find The Array

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
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int x=1,ans=0;
        while (n>0){
            n-=x;
            x+=2;
            ans++;
        }
        cout<<ans<<endl;
    }
}