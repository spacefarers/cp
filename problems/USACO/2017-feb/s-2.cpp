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
ll broken[100005];
int n, k, b;

bool validate(int x){
    if (x>=b) return true;
    if (broken[x]>k) return true;
    if (b-x-1>=0&&n-broken[b-x-1]>=k) return true;
    for (int i=0;i<b-x-1;i++){
        if (broken[i+x+1]-broken[i]>k) {
//            cout<<i<<endl;
            return true;
        }
    }
    return false;
}

int main() {
    setIO("maxcross");
    cin>>n>>k>>b;
    for (int i=0;i<b;i++){
        cin>>broken[i];
    }
    sort(broken, broken+b);
    int left=0,right=b;
    while (left<right){
        int mid=(left+right)/2;
        bool ok=validate(mid);
//        cout<<left<<" "<<right<<" "<<mid<<" "<<ok<<endl;
        if (ok){
            right=mid;
        } else {
            left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;
}