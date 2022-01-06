/*
ID: michael419
LANG: C++11
TASK: wormhole
*/


#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
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

int exits[20], ans=0;
bool visited[20];
set<int> ss;
unordered_map<int, int> mp;
int n;

bool dfs(int x){
    if (visited[x]) {
        return true;
    }
    visited[x]=true;
    auto next = exits[mp[x]];
    if (next==0) return false;
    return dfs(next);
}

void create_comb(){
    if (ss.empty()){
        bool ok=false;
        for (int i=1;i<=n;i++){
            memset(visited, false, sizeof visited);
            if (dfs(i)) ok=true;
        }
        if (ok) ans++;
        return;
    }
    int target=*ss.begin();
    ss.erase(target);
    vi nums;
    trav(i, ss){
        nums.pb(i);
    }
    trav(i, nums){
        ss.erase(i);
        mp[i]=target;
        mp[target]=i;
        create_comb();
        ss.insert(i);
    }
    ss.insert(target);
}

int main() {
    setIO("wormhole");
    cin>>n;
    vector<pair<pi, int>> portals(n+1);
    for (int i=1;i<=n;i++){
        ss.insert(i);
        cin>>portals[i].f.f>>portals[i].f.s;
        portals[i].s=i;
    }
    portals[0]={{0x7fffffff, -1}, 0};
    trav(i, portals){
        int next=0;
        trav(j, portals){
            if (i.f.s==j.f.s&&j.f.f<portals[next].f.f&&j.f.f>i.f.f)
                next=j.s;
        }
        exits[i.s]=next;
    }
    create_comb();
    cout<<ans<<endl;
    return 0;
}

