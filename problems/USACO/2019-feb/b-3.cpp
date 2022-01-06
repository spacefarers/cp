#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
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
int n;
vector<pair<int, pair<int, int>>> sensors;

int main() {
    setIO("traffic");
    cin>>n;
    for (int i=1;i<=n;i++){
        string a;
        int b, c, d;
        cin>>a>>b>>c;
        switch (a.size()) {
            case 2:
                d=1;
                break;
            case 3:
                d=-1;
                break;
            case 4:
                d=0;
                break;
        }
        sensors.pb({d, {b, c}});
    }
    int c_min=-1, c_max=-1;
    for (int e=sensors.size()-1;e>=0;e--){
        auto i=sensors[e];
        if (c_min==-1) {
            if (i.first==0){
                c_min=i.second.first;
                c_max=i.second.second;
            }
            continue;
        }
        if (i.first==1){
            c_min-=i.second.second;
            c_max-=i.second.first;
        } else if (i.first==-1){
            c_min+=i.second.first;
            c_max+=i.second.second;
        } else {
            c_min=max(c_min, i.second.first);
            c_max=min(c_max, i.second.second);
        }
    }
    c_min=max(c_min, 0);
    c_max=max(c_max, 0);
    cout<<c_min<<" "<<c_max<<endl;
    c_min=-1, c_max=-1;
    trav(i, sensors){
        if (c_min==-1) {
            if (i.first==0){
                c_min=i.second.first;
                c_max=i.second.second;
            }
            continue;
        }
        if (i.first==-1){
            c_min-=i.second.second;
            c_max-=i.second.first;
        } else if (i.first==1){
            c_min+=i.second.first;
            c_max+=i.second.second;
        } else {
            c_min=max(c_min, i.second.first);
            c_max=min(c_max, i.second.second);
        }
    }
    c_min=max(c_min, 0);
    c_max=max(c_max, 0);
    cout<<c_min<<" "<<c_max<<endl;
    return 0;
}