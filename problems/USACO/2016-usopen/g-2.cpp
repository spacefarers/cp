#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <unordered_set>

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

vi paths[200005];
int father[200005];
bool ans[200005];


unordered_set<int> avails;

int find(int a){
    if (father[a]!=a) father[a]=find(father[a]);
    return father[a];
}

void unionn(int a, int b){
    int c=find(a);
    int d=find(b);
    father[c]=d;
}

int main() {
    setIO("closing");
    int n, m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        paths[a].pb(b);
        paths[b].pb(a);
    }
    vi q(n);
    for (int i=0;i<n;i++){
        father[i+1]=i+1;
        cin>>q[i];
    }
    reverse(all(q));
    unordered_set<int> not_in;
    for (int I=0;I<n;I++){
        int i=q[I];
        avails.insert(i);
        trav(j, paths[i]){
            if (avails.find(j)!=avails.end())
                unionn(i, j);
        }
        not_in.insert(i);
        vi list;
        trav(j, not_in) if (find(j)==find(q[0])) list.pb(j);
        trav(j, list) not_in.erase(j);
        ans[I]=not_in.empty();
    }
    for (int i=n-1;i>=0;i--){
        if (ans[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}