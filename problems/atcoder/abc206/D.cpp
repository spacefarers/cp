// created on 6/19/21 by spacefarers
// problem: D - KAIBUNsyo

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;

int nums[200005],father[200005];

int find(int x){
    if (father[x]!=x) father[x]=find(father[x]);
    return father[x];
}

void unionn(int a,int b){
    int c=find(a),d=find(b);
    father[c]=d;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<200005;i++){
        father[i]=i;
    }
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    set<pair<int,int>> misses;
    for (int i=0;i<=n/2;i++){
        if (nums[i]!=nums[n-i-1]){
            int a=nums[i],b=nums[n-i-1];
            if (a>b) swap(a,b);
            misses.insert({a,b});
        }
    }
    int ans=0;
    for (auto i:misses){
        if (find(i.f)!=find(i.s)){
            ans++;
            unionn(i.f,i.s);
        }
    }
    cout<<ans<<endl;
}