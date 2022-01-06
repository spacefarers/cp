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

int modd(int a, int b){

}

int main() {
//    setIO("");
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int nums[n];
        for (int i=0;i<n;i++){
            cin>>nums[i];
        }
        int ans1=0;
        for (int i=1;i<n-1;i++){
            ans1+=abs(nums[i]-nums[i+1]);
        }
        int sum1=0;
        vpi contributions;
        for (int i=1;i<n;i++){
            sum1+=nums[i]-nums[0];
        }
        for (int i=1;i<n;i++){
            contributions.pb({abs(sum1+(nums[i]-nums[i-1]*(n-i))), i});
        }
        sort(all(contributions), greater<pi>());

    }
    return 0;
}