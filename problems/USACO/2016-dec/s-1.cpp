#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <set>
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

ll n, q;
vi a;

int search(ll x){
    x++;
    ll left=0, right=a.size()-1;
    while (left<=right){
        ll mid=(left+right)/2;
        if (a[mid]>=x){
            right=mid-1;
        } else if (a[mid]==x) {
            return mid;
        } else {
            left=mid+1;
        }
    }
    return left;
}

int main() {
    setIO("haybales");
    cin>>n>>q;
    a.rsz(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    for (int i=0;i<q;i++){
        ll x, y;
        cin>>x>>y;
        cout<<search(y)-search(x-1)<<endl;
    }
    return 0;
}