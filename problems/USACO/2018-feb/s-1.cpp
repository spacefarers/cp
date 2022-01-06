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

ll l, n, rf, rb, ans=0, last_pos=0, x[100005], k[100005], id[100005], c_pos=0;

bool cmp(int a, int b){
    return k[a]>k[b];
}

int main() {
    setIO("reststops");
    cin>>l>>n>>rf>>rb;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        x[i]=a;
        k[i]=b;
        id[i]=i;
    }
    sort(id, id+n, cmp);
    while (c_pos<n){
        ll a=id[c_pos];
        if (x[a]>last_pos){
            ans+=(rf-rb)*(x[a]-last_pos)*(k[a]);
            last_pos=x[a];
        }
        c_pos++;
    }
    cout<<ans<<endl;
    return 0;
}