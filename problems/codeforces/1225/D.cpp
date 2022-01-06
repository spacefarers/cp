// created on 6/18/21 by spacefarers
// problem: D. Power Products

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

map<int,int> prime_fact(int x){
    map<int,int> mp;
    while (x%2==0){
        x/=2;
        mp[2]++;
    }
    for (int i=3;i*i<=x;i+=2){
        while (x%i==0){
            x/=i;
            mp[i]++;
        }
    }
    if (x!=1) mp[x]++;
    return mp;
}

int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        prime_fact(a);
    }
}