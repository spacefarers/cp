#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
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

int n, p, x[1005], y[1005], mst=0, father[1005];
bool visited[1005];

int find(int i){
    if (i!=father[i]) father[i]=find(father[i]);
    return father[i];
}

void unionn(int a, int b){
    int c=find(a);
    int d=find(b);
    father[c]=d;
}

int main() {
    setIO("moocast");
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> q;
//    Minimum Spanning Tree Example
//    Kruskal's algorithm
    for (int i=0;i<n;i++){
        father[i]=i;
        for (int j=0;j<n;j++){
            if (i==j) continue;
            q.push({pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2), {i, j}});
        }
    }
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        if (find(u.s.f)==find(u.s.s)) continue;
        unionn(u.s.f, u.s.s);
        mst=max(mst, u.f);
    }
    cout<<mst<<endl;
    return 0;
}