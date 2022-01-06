// created on 2021/7/4 by spacefarers
// problem: B - Factorial Yen Coin

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n;
    cin>>n;
    int c=3628800,d=10,ans=0;
    while (n>0){
        for (int i=0;i<10;i++){
            if (n<c) break;
            n-=c;
            ans++;
        }
        c/=d--;
    }
    cout<<ans<<endl;
}