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

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vi desires, rooms;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        desires.pb(a);
    }
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        rooms.pb(a);
    }
    sort(all(desires));
    sort(all(rooms));
    ll a=0, b=0, ans=0;
    while (a<n&&b<m){
        if (abs(desires[a]-rooms[b])<=k) {
            ans++;
            a++;
            b++;
        } else if (desires[a]<rooms[b]){
            a++;
        } else {
            b++;
        }
    }
    cout<<ans<<endl;
    return 0;
}