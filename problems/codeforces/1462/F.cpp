// created on 2021/7/3 by spacefarers
// problem: F. The Treasure of The Segments

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

#define MAX 200005

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int c=1;
        vector<int> l,r;
        vector<pair<int,int>> ranges;
        for (int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            l.push_back(a);
            r.push_back(b);
            ranges.emplace_back(a,b);
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        ll ans=1e9;
        for (auto i:ranges){
            ll r_ans=prev(lower_bound(r.begin(),r.end(),i.f))-r.begin()+1;
            ll l_ans=l.end()-upper_bound(l.begin(),l.end(),i.s);
            ans=min(ans,r_ans+l_ans);
        }
        cout<<ans<<endl;
    }
}