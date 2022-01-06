// created on 2021/6/26 by spacefarers
// problem: B - Hydrate

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (c*d-b<=0) cout<<-1<<endl;
    else cout<<(a-1)/(c*d-b)+1<<endl;
}