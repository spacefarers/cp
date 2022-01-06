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
    setIO("cardgame");
    int n;
    cin>>n;
    vi e_cards, b_cards, half_e_cards1, half_e_cards2, half_b_cards;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        e_cards.pb(a);
        if (i<n/2) half_e_cards1.pb(a);
        else half_e_cards2.pb(a);
    }
    sort(all(e_cards));
    int c=0, d=0, ans=0;
    for (int i=1;i<=2*n;i++){
        if (e_cards[c]==i) c++;
        else {
            if (b_cards.size()<n/2)
                b_cards.pb(i);
            else half_b_cards.pb(i);
        }
    }
    sort(all(half_e_cards1));
    sort(all(half_e_cards2), greater<int>());
    sort(all(b_cards), greater<int>());
    c=0;
    while (c<n/2 and d<n/2){
        if (half_e_cards1[c]>=half_b_cards[d]) d++;
        else {
            ans++;
            d++;
            c++;
        }
    }
    c=0;d=0;
    while (c<n/2 and d<n/2){
        if (half_e_cards2[c]<=b_cards[d]) d++;
        else {
            ans++;
            d++;
            c++;
        }
    }
    cout<<ans<<endl;
    return 0;
}