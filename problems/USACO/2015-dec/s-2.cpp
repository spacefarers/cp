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
    setIO("highcard");
    int n;
    cin>>n;
    vi e_cards, b_cards;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        e_cards.pb(a);
    }
    sort(all(e_cards));
    int c=0, d=0, ans=0;
    for (int i=1;i<=2*n;i++){
        if (e_cards[c]==i) c++;
        else b_cards.pb(i);
    }
    c=0;
    while (c<n and d<n){
        if (e_cards[c]>=b_cards[d]) d++;
        else {
            ans++;
            d++;
            c++;
        }
    }
    cout<<ans<<endl;
    return 0;
}