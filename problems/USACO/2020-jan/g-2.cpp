// created on 2021/6/13 by spacefarers
// problem: Farmer John Solves 3SUM
// I don't think this is a very good problem, it pushes the constants too far, defining 2*5005*5005 variables would go out of space.
// Normal hash functions like unordered_map are also beaten out time wise even though it has the same complexity.

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long

using namespace std;

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll ans[5005][5005];
int nums[5005];

int main(){
    setIO("threesum");
    int n,q;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    for (int i=0;i<n;i++){
        gp_hash_table<int,int> table({},{},{},{},{1<<13});
        for (int j=i+1;j<n;j++){
            int target=-nums[i]-nums[j];
            auto it=table.find(target);
            if (it!=table.end()) ans[i][j]=it->second;
            table[nums[j]]++;
        }
    }
    for (int i=n-1;i>=0;i--){
        for (int j=i+2;j<n;j++){
            ans[i][j]+=ans[i+1][j]+ans[i][j-1]-ans[i+1][j-1];
        }
    }
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<ans[a-1][b-1]<<endl;
    }
}

// Old Version

//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//#include <map>
//
//#define ll long long
//#define f first
//#define s second
//
//using namespace std;
//
//ll ans[5005][5005];
//int nums[5005];
//int prefix[5005][5005];
//map<int,int> mp;
//
//void setIO(const string& name) {
//    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    freopen((name+".in").c_str(),"r",stdin);
//    freopen((name+".out").c_str(),"w",stdout);
//}
//
//int main(){
//    setIO("threesum");
//    int N,Q;
//    cin>>N>>Q;
//    int cnt=0;
//    for (int i=0;i<N;i++){
//        int a;
//        cin>>a;
//        nums[i]=a;
//        if (!mp[a]) mp[a]=++cnt;
//        prefix[mp[a]][i]=1;
//    }
//    for (int i=1;i<=cnt;i++){
//        for (int j=1;j<N;j++){
//            prefix[i][j]+=prefix[i][j-1];
//        }
//    }
//    for (int i=N-3;i>=0;i--){
//        for (int j=i+2;j<N;j++){
//            int target=-nums[i]-nums[j];
//            int added=0;
//            if (mp[target]){
//                target=mp[target];
//                added=prefix[target][j-1]-prefix[target][i];
//            }
//            ans[i][j]=ans[i][j-1]+ans[i+1][j]-ans[i+1][j-1]+added;
//        }
//    }
//    for (int i=0;i<Q;i++){
//        int a,b;
//        cin>>a>>b;
//        cout<<ans[a-1][b-1]<<endl;
//    }
//}