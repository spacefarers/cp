// created on 2021/7/8 by spacefarers
// problem: A. Exciting Bets

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
        ll a,b;
        cin>>a>>b;
        ll diff=abs(a-b);
        cout<<diff<<" ";
        ll dist;
        if (diff!=0)
            dist=min(a%diff,diff-a%diff);
        else dist=0;
        cout<<dist<<endl;
    }
}