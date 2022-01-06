#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define f first
#define s second

int collect[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int a, b, k;
        cin>>a>>b>>k;
        memset(collect, 0, sizeof collect);
        vector<pair<int, int>> pairs(k);
        for (int i=0;i<k;++i){
            cin>>pairs[i].f;
        }
        for (int i=0;i<k;++i){
            cin>>pairs[i].s;
        }
        sort(pairs.begin(), pairs.end());
        long long sum=0, ans=0, last=-1, c_sum=0;
        for (auto &i:pairs){
            if (last!=i.f){
                last=i.f;
                sum+=c_sum;
                c_sum=0;
            }
            ans+=sum-collect[i.s];
            c_sum++;
            collect[i.s]++;
        }
        cout<<ans<<endl;
    }
}