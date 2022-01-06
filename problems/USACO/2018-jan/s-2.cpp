#include <iostream>
#include <fstream>
#include <string>
#include <queue>
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

ll n, m, r, rent_num=0, sell_on=0, ans=0, a, b;
ll cows[100005], rent[100005];
pair<ll, ll> sell[100005];

int main() {
    setIO("rental");
    cin>>n>>m>>r;
    for (int i=0;i<n;i++){
        cin>>cows[i];
    }
    for (int i=0;i<m;i++){
        cin>>sell[i].s>>sell[i].f;
    }
    for (int i=0;i<r;i++){
        cin>>rent[i];
    }
    sort(cows, cows+n, greater<int>());
    sort(sell, sell+m, greater<pair<int, int>>());
    sort(rent, rent+r, greater<int>());
    for (int i=0;i<n-rent_num;i++){
        int sell_profit=0, j, sell_left=0, backup_milk=cows[i];
        for (j=sell_on;j<m;j++){
            if (sell[j].second>=cows[i]) {
                sell_profit+=sell[j].first*cows[i];
                sell_left=sell[j].second-cows[i];
                break;
            } else {
                cows[i]-=sell[j].second;
                sell_profit+=sell[j].second*sell[j].first;
            }
        }
        if (sell_profit>rent[rent_num]){
//            cout<<"sell!"<<endl;
            sell_on=j;
            sell[sell_on].second=sell_left;
            ans+=sell_profit;
        } else {
//            cout<<"rent!"<<endl;
            cows[i]=backup_milk;
            if (rent_num<r) {
                ans+=rent[rent_num];
            }
            rent_num++;
            i--;
        }
    }
    cout<<ans<<endl;
    return 0;
}