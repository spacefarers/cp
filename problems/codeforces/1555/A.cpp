// created on 2021/7/30 by spacefarers
// problem: A. PizzaForces

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
        ll n;
        cin>>n;
        if (n%2) n++;
        if (n<6) n=6;
        cout<<n/2*5<<endl;
    }
}