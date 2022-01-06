#include <iostream>
#include <fstream>
#include <string>
#include <queue>

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


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main() {
    setIO("word");
    int a, b, d;
    string c;
    cin>>a>>b;
    d=0;
    bool first=true;
    F0R (i, a){
        cin>>c;
        bool add;
        if (c.size()+d<=b){
            d+=c.size();
            add=true;
        } else {
            cout<<endl;
            d=c.size();
            add=false;
        }
//        cout<<c.size()+d;
        if (first) {
            add=false;
            first = false;
        }
        cout<<(add?" ":"")<<c;
    }
    return 0;
}