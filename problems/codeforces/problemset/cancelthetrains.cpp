#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

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

int main() {
//    setIO("");
    int t;
    cin>>t;
    while (t--){
        int n, m;
        cin>>n>>m;
        vi bottom, left;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            bottom.pb(a);
        }
        for (int i=0;i<m;i++) {
            int a;
            cin>>a;
            left.pb(a);
        }
        int c_b=0, c_l=0, ans=0;
        while (c_b<bottom.size()&&c_l<left.size()){
            if (bottom[c_b]>left[c_l]){
                c_l++;
            } else if (bottom[c_b]<left[c_l]){
                c_b++;
            } else {
                c_l++;
                c_b++;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}