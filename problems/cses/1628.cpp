// created on 2021/7/10 by spacefarers
// problem: Meet in the Middle

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    map<int,int> num1,num2;
    vector<int> v1,v2;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (i<n/2) v1.push_back(a);
        else v2.push_back(a);
    }
    for (int i=0;i<(1<<n/2);i++){
        ll sum=0;
        for (int j=0;j<n/2;j++){
            if ((1<<j)&i){
                sum+=v1[j];
            }
        }
        if (sum<=x&&sum>0) num1[(int)sum]++;
    }
    for (int i=0;i<(1<<(n-n/2));i++){
        ll sum=0;
        for (int j=0;j<(n-n/2);j++){
            if ((1<<j)&i){
                sum+=v2[j];
            }
        }
        if (sum<=x&&sum>0) num2[(int)sum]++;
    }
    ll ans=0;
    for (auto i:num1){
        if (i.f==x) ans+=i.s;
        else ans+=i.s*num2[x-i.f];
    }
    ans+=num2[x];
    cout<<ans<<endl;
}