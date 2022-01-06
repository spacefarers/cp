// created on 2021/6/27 by spacefarers
// problem: A - God Sequence

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
    vector<int> ans;
    int last=0;
    for (int i=1;i<=a-1;i++){
        ans.push_back(i);
        last+=i;
    }
    for (int i=1;i<=b-1;i++){
        ans.push_back(-i);
        last-=i;
    }
    if (last>=0){
        ans.push_back(20000);
        ans.push_back(-(20000+last));
    } else {
        ans.push_back(-20000);
        ans.push_back(20000-last);
    }
    for (auto i:ans){
        cout<<i<<" ";
    }
}