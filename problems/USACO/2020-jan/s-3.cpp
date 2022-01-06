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
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vpi;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) ll(x.size())
#define all(x) begin(x), end(x)

ll n, m, cows[100005], father[100005];
vpi adjs[100005];

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main() {
    setIO("wormsort");
    cin>>n>>m;
    F0R(i, n){
        cin>>cows[i+1];
    }
    F0R(i, m){
        ll a, b, c;
        cin>>a>>b>>c;
        adjs[a].pb({b, c});
        adjs[b].pb({a, c});
    }
    ll left=0, right=1e12;
    while(left<right){
        ll mid=(left+right+1)/2;
        bool fine=true;
        ll count=1;
        ll visited[100005];
        memset(visited, -1, sizeof(visited));
        for (int i=1;i<=n;i++){
            if (visited[i]==-1){
                queue<int> q;
                q.push(i);
                while (!q.empty()){
                    ll a=q.front();
                    q.pop();
                    visited[a]=count;
                    trav(b, adjs[a]){
                        if (b.second>=mid&&visited[b.first]==-1) q.push(b.first);
                    }
                }
                count++;
            }
        }
        for (int i=1;i<=n;i++){
            if (visited[i]!=visited[cows[i]]){
                fine=false;
                break;
            }
        }
        if (fine){
            left=mid;
        } else {
            right=mid-1;
        }
    }
    if (left==1e12) left=-1;
    cout<<left<<endl;
    return 0;
}