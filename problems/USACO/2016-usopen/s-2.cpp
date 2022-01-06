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

int left1[50005], right1[50005];

int main() {
    setIO("diamond");
    int n, k;
    cin>>n>>k;
    vi nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(all(nums));
    for (int i=0, j=0;i<n;i++){
        while (j<n&&nums[j]-nums[i]<=k) {
            j++;
            left1[j]=max(left1[j], j-i);
        }
        right1[i]=max(right1[i], j-i);
    }
    for (int i=1;i<n;i++){
        left1[i]=max(left1[i], left1[i-1]);
    }
    for (int i=n-2;i>=0;i--){
        right1[i]=max(right1[i], right1[i+1]);
    }
    int best=0;
    for (int i=0;i<n;i++){
        best=max(best, left1[i]+right1[i]);
    }
    cout<<best<<endl;
    return 0;
}