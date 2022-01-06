// created on 2021/7/18 by spacefarers
// problem: A - Arithmetic Sequence

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll mx=max(a,max(b,c));
    ll sum=mx-a+mx-b+mx-c;
    ll front=min(mx-b,(mx-a)/2),back=min(mx-b,(mx-c)/2);
    cout<<sum-max(front,back)*3<<endl;
}