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

int main() {
    int n;
    vi nums;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.pb(a);
    }
    sort(all(nums));
    ll last=-1, ans=0;
    trav(i, nums){
        if (i!=last) {
            ans++;
            last=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}