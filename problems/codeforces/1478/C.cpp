#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long d[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        map<long long, long long, greater<long long>> counts;
        for (int i=0;i<2*n;++i){
            long long a;
            cin>>a;
            counts[a]++;
        }
        bool ok=true;
        for (auto &i:counts){
            if (i.second!=2) ok=false;
        }
        if (!ok) {
            cout<<"NO"<<endl;
            continue;
        }
        long long last=-1, pos=0;
        for (auto &i:counts){
            if (last!=-1) {
                long long c_bars=abs(2*pos-2*n); // n is half the count
                if ((last-i.first)%c_bars) {
                    ok=false;
                    break;
                }
                d[pos]=(last-i.first)/c_bars;
            }
            last=i.first;
            pos++;
        }
        auto it=counts.end();
        it--;
        long long ans=it->first;
        for (int i=1;i<n;i++){
            ans-=2*i*d[i];
        }
        if (!ok||ans%(2*n)||ans<=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}