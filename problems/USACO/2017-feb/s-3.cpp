#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <map>
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

map<pair<pi, pi>, bool> mp;
map<pi, pi> father;
map<pi, bool> has_cow;
map<pi, bool> visited;
map<pi, int> count1;
vpi cows;
int n, k, r;

pi find(pi a){
    if (father[a]!=a) father[a]=find(father[a]);
    return father[a];
}

void unionn(pi a, pi b){
    auto c=find(a);
    auto d=find(b);
    father[c]=d;
}

void dfs(pi a, pi b){
    if (visited[a]||a.f<=0||a.s<=0||a.f>n||a.s>n) return;
//    cout<<a.f<<" "<<a.s<<": "<<b.f<<" "<<b.s<<endl;
    visited[a]=true;
    if (has_cow[a]) unionn(a, b);
    pi new_pi={a.f-1, a.s};
    if (!mp[{a, new_pi}]&&!mp[{new_pi, a}]) dfs(new_pi, b);
    new_pi={a.f+1, a.s};
    if (!mp[{a, new_pi}]&&!mp[{new_pi, a}]) dfs(new_pi, b);
    new_pi={a.f, a.s-1};
    if (!mp[{a, new_pi}]&&!mp[{new_pi, a}]) dfs(new_pi, b);
    new_pi={a.f, a.s+1};
    if (!mp[{a, new_pi}]&&!mp[{new_pi, a}]) dfs(new_pi, b);
}

int main() {
    setIO("countcross");
    cin>>n>>k>>r;
    for (int f=1;f<=r;f++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        mp[{{a, b}, {c, d}}]=true;
    }
    for (int i=0;i<k;i++){
        int a, b;
        cin>>a>>b;
        pi c={a, b};
        cows.pb(c);
        father[c]=c;
        has_cow[c]=true;
    }
    trav (i, cows){
        dfs(i, i);
    }
    int ans=0;
    trav (i, cows){
        count1[father[i]]++;
    }
    int sum_all=0;
    trav (i, count1){
        sum_all+=i.s;
    }
    trav (i, count1){
        ans+=(sum_all-i.s)*i.s;
    }
    cout<<ans/2<<endl;
    return 0;
}