#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

#define ll long long

ll sums[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(sums, 0, sizeof sums);
        int n, m;
        cin>>n>>m;
        vector<int> a;
        set<pair<int, int>> ss;
        for (int i=0;i<n;i++){
            int b;
            cin>>b;
            a.push_back(b);
        }
        sums[0]=a.front();
        ss.insert({sums[0], 0});
        ll max_pos=0;
        for (int i=1;i<n;i++){
            sums[i]=sums[i-1]+a[i];
            if (sums[i]>sums[max_pos]) {
                max_pos=i;
                ss.insert({sums[i], i});
            }
        }
        for (int i=0;i<m;i++){
            ll x, ans=0;
            cin>>x;
            if (x>sums[max_pos]){
                if (sums[n-1]<=0) {
                    cout<<-1<<" ";
                    continue;
                }
                ll turns=(x-sums[max_pos]+sums[n-1]-1)/sums[n-1];
                x-=turns*sums[n-1];
                ans+=turns*n;
            }
            auto it=ss.lower_bound({x, -0x7fffffff});
            cout<<ans+(*it).second<<" ";
        }
        cout<<endl;
    }
}