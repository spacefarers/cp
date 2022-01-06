// created on 2021/7/2 by spacefarers
// problem: D. Replace by MEX

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;

int nums[1005];
int n;

bool check(){
    for (int i=0;i<n;i++){
        if (nums[i]!=i) return false;
    }
    return true;
}

map<int,set<int>> mp;

int get_MEX(){
    int ans=-1;
    while (!mp[++ans].empty());
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        mp.clear();
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            mp[a].insert(i);
            nums[i]=a;
        }
        vector<int> ans;
        int MEX;
        while ((MEX=get_MEX())!=n||!check()){
            if (MEX==n){
                for (int i=0;i<n;i++){
                    if (nums[i]!=i){
                        MEX=nums[i];
                        nums[i]=n;
                        mp[n].insert(i);
                        mp[MEX].erase(i);
                        ans.push_back(i);
                        break;
                    }
                }
            }
            ans.push_back(MEX);
            int orig=nums[MEX];
            mp[orig].erase(MEX);
            nums[MEX]=MEX;
            mp[MEX].insert(MEX);
        }
        cout<<ans.size()<<endl;
        for (auto i:ans){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}