#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long lengths[100005], a[100005], b[100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(lengths, 0, sizeof lengths);
        for (int i=0;i<n;++i) cin>>lengths[i];
        for (int i=0;i<n;++i) cin>>a[i];
        for (int i=0;i<n;++i) cin>>b[i];
        long long c=0, max_all=0;
        for (int i=1;i<n;++i){
            long long u=lengths[i]+1+abs(a[i]-b[i]);
            if (a[i]==b[i]) c=u;
            else c=max(u, c+lengths[i]+1-abs(a[i]-b[i]));
            max_all=max(max_all, c);
        }
        cout<<max_all<<endl;
    }
}