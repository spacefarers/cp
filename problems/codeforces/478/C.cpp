// created on 2021/6/21 by spacefarers
// problem: C. Table Decorations

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    ll r,g,b;
    cin>>r>>g>>b;
    r=min(r,2*(g+b));
    g=min(g,2*(r+b));
    b=min(b,2*(g+r));
    cout<<(r+b+g)/3<<endl;
}