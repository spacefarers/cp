#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include <unordered_set>

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

int mas[200005];

int main() {
//    setIO("");
    int n;
    cin>>n;
    int best=0;
    for (int i=0;i<n;i++){
        cin>>mas[i];
    }
    map<int, int> mp;
    for (int i=0, j=0;i<n;i++){
        while (j<n&&mp[mas[j]]<1) mp[mas[j++]]++;
        mp[mas[i]]--;
        best=max(best, j-i);
    }
    cout<<best<<endl;
    return 0;
}