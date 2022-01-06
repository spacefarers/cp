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

int father[100005];

int find(int a){
    if (a!=father[a]) father[a]=find(father[a]);
    return father[a];
}

void unionn(int a, int b){
    int c=find(a);
    int d=find(b);
    father[c]=d;
}

int minl[100005], maxr[100005];

int main() {
    setIO("moop");
    int n;
    cin>>n;
    vector<pair<pi, int>> points;
    for (int i=0;i<n;i++){
        ll a, b;
        father[i]=i;
        cin>>a>>b;
        points.pb({{a, b}, i});
    }
    sort(all(points));
    int ans=1;
    minl[0]=points[0].f.s;
    maxr[n-1]=points[n-1].f.s;
    for (int i=1;i<n;i++){
        minl[i]=min(minl[i-1], points[i].f.s);
    }
    for (int i=n-2;i>=0;i--){
        maxr[i]=max(maxr[i+1], points[i].f.s);
    }
    for (int i=0;i<n-1;i++){
        if (minl[i]>maxr[i+1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

