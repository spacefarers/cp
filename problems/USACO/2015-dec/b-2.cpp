#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
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

vector<pair<pi, int>> roads, b_s;

int main() {
    setIO("speeding");
    int n, m;
    cin>>n>>m;
    int c=0;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        roads.pb({{c, c+a}, b});
        c+=a;
    }
    c=0;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        b_s.pb({{c, a+c}, b});
        c+=a;
    }
    int ans=0;
    trav(i, roads){
        trav(j, b_s){
            if ((i.f.f>j.f.f&&i.f.f<j.f.s)||(i.f.s<j.f.s&&i.f.s>j.f.f)||(i.f.f<=j.f.f&&i.f.s>=j.f.s)||(j.f.f<=i.f.f&&j.f.s>=i.f.s)){
                ans=max(ans, j.s-i.s);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}