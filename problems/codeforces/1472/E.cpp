#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second

int ans[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        memset(ans, -1, sizeof ans);
        set<pair<pair<int,int>,int>> points;
        map<int,pair<int,int>> mins;
        for (int i=0;i<n;++i){
            int a, b;
            cin>>a>>b;
            points.insert({{a, b}, i});
        }
        pair<int,int> min_num={2e9,-2},c={2e9,-2};
        int last=-1;
        for (auto &i:points){
            if (i.f.f!=last){
                if (c.f<min_num.f) min_num=c;
                last=i.f.f;
                c={i.f.s,i.s};
            }
            if (mins[i.f.s].f==0||i.f.f<mins[i.f.s].f) mins[i.f.s]={i.f.f,i.s};
            if (i.f.s>min_num.f) ans[i.s]=min_num.s+1;
        }
        pair<int,int> min_ans={2e9,-2};
        for (auto i:mins){
            if (i.s.f<min_ans.f) min_ans=i.s;
            mins[i.f]=min_ans;
        }
        for (auto &i:points){
            auto it=mins.lower_bound(i.f.f);
            if (it!=mins.begin()&&(*it).s.f!=0){
                it--;
                if ((*it).s.f<i.f.s){
                    ans[i.s]=(*it).s.s+1;
                }
            }
        }
        for (int i=0;i<n;++i) cout<<ans[i]<<" ";
        cout<<endl;
    }
}