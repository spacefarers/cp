#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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
int n, m, k;
vi order;
int pos[105];
bool include_a[105];
vpi exceptions2, exceptions1;
int mp[105];

bool cmp(pi a, pi b){
    int x=a.first, y=b.first;
    trav(i, order){
        if (i==x) return true;
        if (i==y) return false;
    }
    return false;
}

int main() {
//    setIO("milkorder");
    cin>>n>>m>>k;
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        include_a[a]=true;
        order.pb(a);
    }
    for (int i=0;i<k;i++){
        int a, b;
        cin>>a>>b;
        pos[a]=b;
        if (include_a[a])
            exceptions2.emplace_back(a, b);
        else
            exceptions1.emplace_back(a, b);
    }
    sort(all(exceptions2), cmp);
    for (int i=0;i<=n;i++){
        mp[i]=-1;
    }
    int line_pos=1, e_pos=0;
    for (int i=1;i<=n;i++){
        bool skip=false;
        trav(a, exceptions1){
            if (a.f==i) skip=true;
            if (include_a[a.f]){
                for (int j=line_pos;j<a.s;j++){
                    if (pos[line_pos]==0) {
                        pos[line_pos]=
                    }
                }
            }
            pos[a.s]=a.f;
            mp[a.f]=a.s;
        }
        if (skip) continue;
        cout<<i<<endl;
    }
    return 0;
}