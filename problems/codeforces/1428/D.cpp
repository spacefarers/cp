// created on 2021/7/9 by spacefarers
// problem: D. Bouncing Boomerangs

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n;
    cin>>n;
    int x=0;
    vector<int> unprocessed_2,unprocessed_3;
    vector<pair<int,int>> ans;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a==0) continue;
        int loc=x;
        if (a==1&&!unprocessed_2.empty()){
            loc=unprocessed_2.back();
            unprocessed_2.pop_back();
        } else if (!unprocessed_3.empty()){
            int temp=unprocessed_3.back();
            unprocessed_3.pop_back();
            ans.emplace_back(i,temp);
        }
        ans.emplace_back(i,loc);
        if (a==2){
            unprocessed_2.push_back(loc);
        }
        if (a==3){
            unprocessed_3.push_back(loc);
        }
        if (loc==x) x++;
    }
    if (!unprocessed_2.empty()||!unprocessed_3.empty()) cout<<-1<<endl;
    else {
        cout<<ans.size()<<endl;
        for (auto i:ans){
            cout<<i.s+1<<" "<<i.f+1<<endl;
        }
    }
}