#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        long long A, B, n;
        cin>>A>>B>>n;
        vector<pair<long long, long long>> monsters(n);
        long long max_save=0;
        for (int i=0;i<n;i++) {
            cin>>monsters[i].first;
            max_save=max(max_save, monsters[i].first);
        }
        for (int i=0;i<n;i++) {
            cin>>monsters[i].second;
            long long hits=(monsters[i].second+A-1)/A;
            monsters[i].first*=hits;
        }
        sort(monsters.begin(), monsters.end(), greater<pair<long long, long long>>());
        bool ok=true;
        B+=max_save;
        for (int i=0;i<n;i++){
            B-=monsters[i].first;
            if (B<=0) {
                ok=false; break;
            }
        }
        if (ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}