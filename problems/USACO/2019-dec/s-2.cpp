/*
ID: michael419
LANG: C++
TASK: meetings
*/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
#include <numeric>

#define all(x) begin(x), end(x)
#define trav(a,x) for (auto& a: x)
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;



int n, l, w[50005], x[50005], d[50005], t_b=0, t_w=0;


int main() {
    ofstream fout ("meetings.out");
    ifstream fin ("meetings.in");
    fin>>n>>l;
    F0R (i, n) fin >> w[i] >> x[i] >> d[i];
    vi v(n);
    iota(all(v), 0);
    sort(all(v), [](int a, int b){return x[a]<x[b];});
    vi W, X, D;
    trav(z, v){
        W.pb(w[z]);
        X.pb(x[z]);
        D.pb(d[z]);
    }
    vi lef, rig;
    F0R(z, n) {
        if (D[z] == -1) lef.pb(X[z]);
        else rig.pb(X[z]);
    }
    vpi o;
    F0R(i, lef.size()) o.pb({lef[i], W[i]});
    F0R(i, rig.size()) o.pb({l-rig[i], W[i+lef.size()]});
    sort(all(o));
    trav(i, o) t_w+=i.second;
    int f_time = 0;
    trav(z, o){
//        cout<<z.first<<endl;
        t_w-=2*z.second;
        if (t_w<=0) {
            f_time = z.first;
            break;
        }
    }
    queue<int> q2;
    F0R(z, n){
        if (D[z] == -1){
            while (!q2.empty() && q2.front()+2*f_time<X[z]) q2.pop();
            t_b+=q2.size();
        } else q2.push(X[z]);
    }
    fout<<t_b<<endl;
    return 0;
}