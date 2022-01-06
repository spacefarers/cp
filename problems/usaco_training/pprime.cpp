/*
ID: michael419
LANG: C++11
TASK: pprime
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

set<ll> ss;

void check_prime(int x){
    int i=2;
    bool ok=true;
    while (i*i<=x){
        if (x%i==0) {
            ok=false;
            break;
        }
        i++;
    }
    if (ok) ss.insert(x);
}

int main() {
    setIO("pprime");
    int A, B;
    cin>>A>>B;
    for (int i=1;i<=2e4;i+=2){
        string a=to_string(i);
        reverse(all(a));
        string c=a;
        for (int k=0;k<=8;k++) {
            ll b=stoll(a+string(k, '0')+to_string(i));
            if (b<=B&&b>=A) check_prime(b);
        }
        c=c.substr(0, c.size()-1);
        c+=to_string(i);
        ll d=stoll(c);
        if (d<=B&&d>=A) check_prime(d);
    }
    trav(i, ss) cout<<i<<endl;
    return 0;
}

