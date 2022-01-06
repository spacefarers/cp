// created on 2021/7/31 by spacefarers
// problem: A - Alloy

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if (a==0) cout<<"Silver"<<endl;
    else if (b==0) cout<<"Gold"<<endl;
    else cout<<"Alloy"<<endl;
}