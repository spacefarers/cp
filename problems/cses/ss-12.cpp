#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
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
    int x, n;
    cin>>x>>n;
    map<int, int> mp;
    set<int> s;
    s.insert(0);
    s.insert(x);
    mp[x]=1;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        auto it=s.lower_bound(a);
        int r=*it;
        it--;
        int l=*it;
        mp[r-l]--;
        if (mp[r-l]==0) mp.erase(r-l);
        s.insert(a);
        mp[r-a]++;
        mp[a-l]++;
        cout<<(--mp.end())->first<<" ";
    }
    return 0;
}