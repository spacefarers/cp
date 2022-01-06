// created on 2021/7/4 by spacefarers
// problem: C - Fair Candy Distribution

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;
ll ans[200005];
int main(){
    ll n,k;
    cin>>n>>k;
    ll num=k/n,lef=k%n;
    vector<pair<int,int>> people;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        people.emplace_back(a,i);
    }
    sort(people.begin(),people.end());
    for (int i=0;i<n;i++){
        ans[i]=num;
    }
    for (int i=0;i<lef;i++){
        ans[people[i].s]++;
    }
    for (int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}