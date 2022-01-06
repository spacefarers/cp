// created on 2021/7/15 by spacefarers
// problem: C. Manhattan Subarrays

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;

int tree[200005],n;

void setNum(int k,int x){
    while (k<=n){
        tree[k]=max(tree[k],x);
        k+=k&-k;
    }
}

int getMax(int k){
    int ans=0;
    while (k>0){
        ans=max(ans,tree[k]);
        k-=k&-k;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(tree,0,sizeof tree);
        cin>>n;
        set<pair<int,int>> point_left,point_right;
        set<pair<int,int>> setnums;
        vector<int> nums(n+1);
        for (int i=1;i<=n;i++){
            cin>>nums[i];
            setnums.insert({nums[i],i});
        }
        ll ans=0;
        for (int i=1;i<=n;i++){
            int a=nums[i];
            setnums.erase(setnums.find({a,i}));
            auto it1=point_left.upper_bound({a,-1e9}),it2=point_right.lower_bound({a,-1e9});
            if (it1!=point_left.begin()){
                it1--;
                auto it=setnums.lower_bound({a,-1e9});
                if (it!=setnums.end()){
                    setNum(it->s,it1->s);
                }
                if (it1->f==a) point_left.erase(it1);
                it1++;
                while (it1!=point_left.end()) point_left.erase(it1++);
            }
            if (it2!=point_right.end()){
                auto it=setnums.upper_bound({a,-1e9});
                if (it!=setnums.begin()){
                    setNum(prev(it)->s,it2->s);
                }
                if (it2->f==a) point_right.erase(it2);
                while (!point_right.empty()&&point_right.begin()->f<=a) point_right.erase(point_right.begin());
            }
            point_left.insert({a,i});
            point_right.insert({a,i});
        }
        for (int i=1;i<=n;i++){
            ans+=i-getMax(i);
        }
        cout<<ans<<endl;
    }
}