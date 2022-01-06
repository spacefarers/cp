#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
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

vpi nums;

int v(int x){
    return nums[x].f;
}

int p(int x){
    return nums[x].s;
}

int main() {
//    setIO("");
    int n, m;
    cin>>n>>m;
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        nums.pb({a, i+1});
    }
    sort(all(nums));
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int l=j+1, r=n-1;
            while (l<r){
                while (l==i||l==j) l++;
                while (r==i||r==j) r--;
                if (v(l)+v(i)+v(j)+v(r)==m){
                    cout<<p(i)<<" "<<p(j)<<" "<<p(r)<<" "<<p(l)<<endl;
                    return 0;
                } else if (v(l)+v(i)+v(j)+v(r)>m) r--;
                else l++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}

