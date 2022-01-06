// created on 2021/7/3 by spacefarers
// problem: A. Odd Set

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
        n*=2;
        int odd=0;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            if (a%2) odd++;
        }
        if (odd*2==n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}