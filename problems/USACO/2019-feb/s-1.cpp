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

int nums[100004];

int main() {
    setIO("herding");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums, nums+n);
    int right=0, best=0;
    for (int i=0;i<n;i++){
        while (nums[right]<nums[i]+n&&right<n){
            right++;
        }
        best=max(best, right-i);
    }
    if ((nums[1]-nums[0]>2 and nums[n-1]-nums[1]==n-2) or (nums[n-1]-nums[n-2]>2 and nums[n-2]-nums[0]==n-2)) cout<<2<<endl;
    else cout<<n-best<<endl;
    cout<<max(nums[n-1]-nums[1], nums[n-2]-nums[0])-(n-2)<<endl;
    return 0;
}