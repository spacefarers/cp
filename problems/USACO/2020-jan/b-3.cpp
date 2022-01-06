#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

long long k, n, x;
void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}


int main() {
    setIO("race");
    cin>>k>>n;
    F0R(i, n){
        cin>>x;
        ll total=0;
        ll s=0;
        ll count=0;
        while (total<k){
            count++;
            s++;
            if (s>=x) {
                total+=2*s;
                count++;
            }
            else total+=s;
        }
        if (total-s>=k){
            count--;
        }
        cout<<count<<endl;
    }
    return 0;
}