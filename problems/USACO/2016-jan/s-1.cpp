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

int n, k;
vi bales;

bool validate(int r){
    int c=1, d=2*r;
    for (int i=0;i<bales.size()-1;i++){
        if (d>=bales[i+1]-bales[i]){
            d-=bales[i+1]-bales[i];
        } else {
            d=2*r;
            c++;
        }
    }
    return c<=k;
}

int main() {
    setIO("angry");
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        bales.pb(a);
    }
    sort(all(bales));
    int left=0, right=1e9;
    while (left<right){
        int mid=(right+left)/2;
        if (validate(mid)){
            right=mid;
        } else {
            left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;
}