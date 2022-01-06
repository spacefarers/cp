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
    int n, x;
    cin>>n>>x;
    vpi nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i].f;
        nums[i].s=i+1;
    }
    sort(all(nums));
    int l=0, r=n-1;
    while (l<r){
        int c=nums[r].f+nums[l].f;
        if (c<x) l++;
        else if (c>x) r--;
        else {
            cout<<nums[l].s<<" "<<nums[r].s<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}