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

pair<pl, pl> area_left[50005], area_right[50005];

bool cmp(pi a, pi b){
    return a.s<b.s;
}

bool between(ll a, ll b, ll c, ll d){
    return (c>=a&&c<=b)||(d>=a&&d<=b);
}

ll area(pair<pl, pl> a, pair<pl, pl> b){
    return (a.f.f-a.f.s)*(a.s.f-a.s.s)+(b.f.f-b.f.s)*(b.s.f-b.s.s);
}

int main() {
    setIO("split");
    int n;
    ll ans=0, orig_area=0;
    cin>>n;
    vector<pair<ll, ll>> cows;
    for (int i=0;i<n;i++){
        ll a, b;
        cin>>a>>b;
        cows.emplace_back(a, b);
    }
    sort(all(cows));
    ll miny=0x7fffffff, maxy=0;
    trav(i, cows){
        miny=min(miny, i.s);
        maxy=max(maxy, i.s);
    }
    orig_area=(maxy-miny)*(cows[n-1].f-cows[0].f);
    miny=0x7fffffff, maxy=0;
    for (int I=0;I<n;I++){
        auto i=cows[I];
        miny=min(miny, i.s);
        maxy=max(maxy, i.s);
        area_left[I]={{maxy, miny}, {i.f, cows[0].f}};
    }
    miny=0x7fffffff, maxy=0;
    for (int I=n-1;I>=0;I--){
        auto i=cows[I];
        miny=min(miny, i.s);
        maxy=max(maxy, i.s);
        area_right[I]={{maxy, miny}, {cows[n-1].f, i.f}};
    }
    for (int i=0;i<n;i++){
        if (area_left[i].s.s==area_right[i+1].s.s&&(between(area_left[i].f.f, area_left[i].f.s, area_right[i+1].s.f, area_right[i+1].s.s))) continue;
        ans=max(ans, orig_area-(area(area_left[i], area_right[i+1])));
    }
    sort(all(cows), cmp);
    ll minx=0x7fffffff, maxx=0;
    for (int I=0;I<n;I++){
        auto i=cows[I];
        minx=min(minx, i.f);
        maxx=max(maxx, i.f);
        area_left[I]={{maxx, minx}, {i.s, cows[0].s}};
    }
    minx=0x7fffffff, maxx=0;
    for (int I=n-1;I>=0;I--){
        auto i=cows[I];
        minx=min(minx, i.f);
        maxx=max(maxx, i.f);
        area_right[I]={{maxx, minx}, {cows[n-1].s, i.s}};
    }
    for (int i=0;i<n;i++){
        if (area_left[i].s.s==area_right[i+1].s.s&&(between(area_left[i].f.f, area_left[i].f.s, area_right[i+1].s.f, area_right[i+1].s.s))) continue;
        ans=max(ans, orig_area-(area(area_left[i], area_right[i+1])));
    }
    cout<<ans<<endl;
    return 0;
}