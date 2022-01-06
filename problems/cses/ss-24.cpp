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

set<int> bot, top;
int n, k;

void op(int a, int b){
    if (a>*(--bot.end())) top.insert(a);
    else bot.insert(a);
}

int main() {
//    setIO("");
    cin>>n>>k;
    vi nums(n);
    for (int i=0;i<n;i++) cin>>nums[i];
    set<int> ss, ss2;
    for (int i=0;i<k;i++){
        if (i<k/2) ss.insert(nums[i]);
        else ss2.insert(nums[i]);
    }
    for (int i=1;i<n-k;i++){

    }
    return 0;
}

