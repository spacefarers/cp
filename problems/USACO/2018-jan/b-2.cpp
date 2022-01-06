#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n;
vpi a;

int main() {
    setIO("lifeguards");
    cin>>n;
    a.rsz(n);
    for (int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(all(a));
    int ans=0;
    for (int i=0;i<n;i++){
        int c_ans=0;
        int c_pos=0;
        for (int j=0;j<n;j++){
            if (i==j) continue;
            if (c_pos>=a[j].first){
                if (c_pos<=a[j].second){
                    c_ans+=a[j].second-c_pos;
                    c_pos=a[j].second;
                } else
                    continue;
            } else if (c_pos<a[j].first){
                c_ans+=a[j].second-a[j].first;
                c_pos=a[j].second;
            }
        }
        ans=max(ans, c_ans);
    }
    cout<<ans<<endl;
    return 0;
}