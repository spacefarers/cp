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
    int c_pos=0, c_pos_num_line=1;
    trav (i, exceptions2){
        if (include_a[i.f]){
            int c=0;
            while (order[c_pos]!=i.f){
                c++;
                c_pos++;
            }
            c_pos++;
            trav(o, exceptions1){
                if (o.second<i.s&&o.second>c_pos_num_line) c++;
            }
            if (c+c_pos_num_line<i.s-1){
                cout<<c_pos_num_line<<endl;
                return 0;
            } else {
                c_pos_num_line=i.s+1;
            }
        }
    }
    for (int i=c_pos_num_line;i<=n;i++){
        bool ok=true;
        trav(a, exceptions1){
            if (a.s==i) ok=false;
        }
        if (ok) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}