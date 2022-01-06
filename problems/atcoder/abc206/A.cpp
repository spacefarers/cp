// created on 6/19/21 by spacefarers
// problem: A - Maxi-Buying

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    ll n;
    cin>>n;
    n*=108;
    n/=100;
    if (n<206) cout<<"Yay!"<<endl;
    else if (n==206) cout<<"so-so"<<endl;
    else cout<<":("<<endl;
}