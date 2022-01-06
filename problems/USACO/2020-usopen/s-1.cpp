/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll n, m;
vector<pair<ll, ll>> a;

bool validate(ll x){
    ll count=1, current=a[0].first, pos=0;
    while (true){
        if (pos>=m) break;
        if (current+x>a[pos].second){
            pos++;
            continue;
        }
        current+=x;
        if (current<a[pos].first) current=a[pos].first;
        count++;
    }
    return count>=n;
}

int main() {
    setIO("socdist");
    cin>>n>>m;
    a.rsz(m);
    ll max_len=0;
    for (ll i=0;i<m;i++){
        ll x, y;
        cin>>x>>y;
        max_len=max(max_len, y);
        a[i].first=x;
        a[i].second=y;
    }
    sort(all(a));
    ll left=1, right=max_len;
    while (left<right){
//        cout<<left<<" "<<right<<endl;
        ll mid = (left+right+1)/2;
        if (validate(mid)){
            left=mid;
        } else {
            right=mid-1;
        }
    }
    cout<<left<<endl;
    return 0;
}