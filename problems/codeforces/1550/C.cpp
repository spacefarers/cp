// created on 2021/7/14 by spacefarers
// problem: C. Manhattan Subarrays

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        set<pair<int,int>> points_left,points_right;
        map<int,int> mp_left,mp_right;
        ll ans=0;
        for (int i=1;i<=n;i++){
            int a;
            cin>>a;
            int bottleneck=0;
            auto it_left=mp_left.upper_bound(a),it_right=mp_right.lower_bound(a);
            if (it_left!=mp_left.begin()){
                bottleneck=prev(it_left)->s;
            }
            if (it_right!=mp_right.end()){
                bottleneck=max(bottleneck,it_right->s);
            }
            ans+=i-bottleneck;
            auto find_left=points_left.upper_bound({a,-1e9}),find_right=points_right.lower_bound({a,-1e9});
            if (find_left!=points_left.begin()){
                find_left--;
                if (it_left==mp_left.begin()||prev(it_left)->s<find_left->s){
                    while (it_left!=mp_left.end()&&it_left->s<find_left->s) mp_left.erase(it_left++);
                    mp_left[a]=find_left->s;
                }
            }
            if (find_right!=points_right.end()){
                if (it_right==mp_right.end()||it_right->s<find_right->s){
                    if (it_right!=mp_right.begin()){
                        it_right--;
                        while (it_right->s<find_right->s){
                            mp_right.erase(it_right);
                            if (it_right!=mp_right.begin()) it_right--;
                            else break;
                        }
                    }
                    mp_right[a]=find_right->s;
                }
            }
            auto it=points_left.lower_bound({a,-1e9}),it2=points_right.upper_bound({a,-1e9});
            while (it!=points_left.end()) points_left.erase(it++);
            if (it2!=points_right.begin()){
                it2--;
                while (true){
                    points_right.erase(it2);
                    if (it2!=points_right.begin()) it2--;
                    else break;
                }
            }
            points_left.insert({a,i});
            points_right.insert({a,i});
        }
        cout<<ans<<endl;
    }
}