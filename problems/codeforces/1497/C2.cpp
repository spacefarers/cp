// created on 2021/7/3 by spacefarers
// problem: C2. k-LCM (hard version)

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
        int n,k;
        cin>>n>>k;
        int new_n=n-k+3;
        for (int i=0;i<k-3;i++){
            cout<<1<<" ";
        }
        if (new_n%2){
            cout<<new_n/2<<" "<<new_n/2<<" "<<1;
        } else if (new_n%4) {
            cout<<new_n/2-1<<" "<<new_n/2-1<<" "<<2;
        } else {
            cout<<new_n/4<<" "<<new_n/4<<" "<<new_n/2;
        }
        cout<<endl;
    }
}