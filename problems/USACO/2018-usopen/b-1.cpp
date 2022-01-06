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

vector<char> won_single;
vector<pair<char, char>> won_double;
string a, b, c;

void add_single_win(char x){
    trav(i, won_single){
        if (i==x) return;
    }
    won_single.pb(x);
}
void add_double_win(char x, char y, char z){
    if (x==y) x=z;
    if (x==y&&y==z) return;
    trav(i, won_double){
        if ((i.first==x&&i.second==y)||(i.first==y&&i.second==x)) return;
    }
    won_double.emplace_back(x, y);
}

int main() {
    setIO("tttt");
    cin>>a>>b>>c;
//    single
    if (a[0]==a[1]&&a[1]==a[2]) add_single_win(a[0]);
    if (b[0]==b[1]&&b[1]==b[2]) add_single_win(b[0]);
    if (c[0]==c[1]&&c[1]==c[2]) add_single_win(c[0]);
    if (a[0]==b[1]&&b[1]==c[2]) add_single_win(a[0]);
    if (a[2]==b[1]&&b[1]==c[0]) add_single_win(a[2]);
    if (a[0]==b[0]&&b[0]==c[0]) add_single_win(a[0]);
    if (a[1]==b[1]&&b[1]==c[1]) add_single_win(a[1]);
    if (a[2]==b[2]&&b[2]==c[2]) add_single_win(a[2]);

    if (a[0]==a[1]||a[0]==a[2]||a[1]==a[2]) add_double_win(a[0], a[1], a[2]);
    if (b[0]==b[1]||b[0]==b[2]||b[1]==b[2]) add_double_win(b[0], b[1], b[2]);
    if (c[0]==c[1]||c[0]==c[2]||c[1]==c[2]) add_double_win(c[0], c[1], c[2]);
    if (a[0]==b[1]||a[0]==c[2]||c[2]==b[1]) add_double_win(c[2], b[1], a[0]);
    if (a[2]==c[0]||b[1]==c[0]||a[2]==b[1]) add_double_win(c[0], b[1], a[2]);
    if (a[0]==c[0]||b[0]==c[0]||a[0]==b[0]) add_double_win(c[0], b[0], a[0]);
    if (a[1]==c[1]||b[1]==c[1]||a[1]==b[1]) add_double_win(c[1], b[1], a[1]);
    if (a[2]==c[2]||b[2]==c[2]||a[2]==b[2]) add_double_win(c[2], b[2], a[2]);
    cout<<won_single.size()<<endl<<won_double.size()<<endl;
    return 0;
}