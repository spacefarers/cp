#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll n, q, pos=0, counts[100005], ids[100005], ans[100005];
int father[100005];
pair<ll,ll> query[100005];
vector<pair<ll, pair<int, int>>> paths;

int find(int x){
    if (x!=father[x]) {
        counts[father[x]]+=counts[x];
        counts[x]=0;
        father[x]=find(father[x]);
    }
    return father[x];
}

void unionn(int x, int y){
    int a=find(x);
    int b=find(y);
    if (a!=b){
        counts[b]+=counts[a];
        counts[a]=0;
        father[a]=b;
    }
}

bool cmp(int a, int b){
    return query[a].f>query[b].f;
}

int main() {
//    setIO("mootube");
    cin>>n>>q;
    for (int i=0;i<n-1;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        paths.push_back({c, {a-1, b-1}});
    }
    for (int i=0;i<n;i++){
        father[i]=i;
        counts[i]=1;
        ids[i]=i;
    }
    sort(paths.begin(),paths.end(), greater<pair<int, pi>>());
    for (int i=0;i<q;i++){
        ll k, s;
        cin>>k>>s;
        query[i]={k, s-1};
    }
    sort(ids, ids+q, cmp);
    for (int i=0;i<q;i++){
        while (pos<paths.size()&&paths[pos].f>=query[ids[i]].f){
            unionn(paths[pos].s.f, paths[pos].s.s);
            pos++;
        }
        ans[ids[i]] = counts[find(query[ids[i]].s)];
    }
    for (int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}