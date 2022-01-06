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

int main() {
//    setIO("");
    int n, m;
    cin>>n>>m;
    vi customers;
    set<pi> tickets;
    customers.rsz(m);
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        tickets.insert({a, i});
    }
    for (int i=0;i<m;i++) cin>>customers[i];
    ll ans=0;
    trav(i, customers){
        auto a=tickets.lower_bound({i+1, 0});
        if (a==tickets.begin()) {cout<<-1<<endl;continue;}
        --a;
        cout<<(*a).first<<endl;
        tickets.erase(a);
    }
    return 0;
}