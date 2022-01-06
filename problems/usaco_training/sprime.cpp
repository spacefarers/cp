/*
ID: michael419
LANG: C++11
TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
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


bool check_prime(ll x){
    ll i=2;
    while (i*i<=x){
        if (x%i==0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    setIO("sprime");
    int n;
    cin>>n;
    set<ll> ss;
    ss.insert(2);
    ss.insert(3);
    ss.insert(5);
    ss.insert(7);
    for (int i=1;i<n;i++){
        vl new_one;
        trav(j, ss){
            for (int k=1;k<=9;k++) {
                ll a = j * 10 + k;
                if (check_prime(a)) new_one.pb(a);
            }
        }
        ss.clear();
        trav(j, new_one) ss.insert(j);
    }
    trav(i, ss) cout<<i<<endl;
    return 0;
}

