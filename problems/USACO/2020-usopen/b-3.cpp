/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
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


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
int n, t;
bool cows[500];
string a;
vector<vi> shakes;

bool cmp(vi b, vi c){
    return b[0]<c[0];
}

bool validate(int zero, int k){
    bool infected[500];
    int infect_times[500];
    memset(infected, false, sizeof(infected));
    memset(infect_times, 0, sizeof(infect_times));
    infected[zero]=true;
    trav(i, shakes){
        if (infected[i[1]]&&infect_times[i[1]]<k){
            if (infected[i[2]]) infect_times[i[2]]++;
            else infected[i[2]]=true;
            infect_times[i[1]]++;
        } else if (infected[i[2]]&&infect_times[i[2]]<k){
            if (infected[i[1]]) infect_times[i[1]]++;
            else infected[i[1]]=true;
            infect_times[i[2]]++;
        }
    }
    for (int i=1;i<=n;i++){
        if (cows[i]!=infected[i]){
            return false;
        }
    }
    return true;
}

int main() {
    setIO("tracing");
    cin>>n>>t;
    cin>>a;
    for (int i=1;i<=n;i++){
        cows[i]=(a[i-1]=='1');
    }
    shakes.rsz(t);
    for (int i=0;i<t;i++){
        shakes[i].rsz(3);
        cin>>shakes[i][0]>>shakes[i][1]>>shakes[i][2];
    }
    sort(all(shakes), cmp);
    int max_k=0, min_k=0x7ffffff, pos_zero=0, last_zero=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=t;j++){
            if (validate(i, j)){
                if (i!=last_zero){
                    pos_zero++;
                    last_zero=i;
                }
                max_k=max(max_k, j);
                min_k=min(min_k, j);
            }
        }
    }
    string max_kk = ((max_k==t)?"Infinity":to_string(max_k));
    cout<<pos_zero<<" "<<min_k<<" "<<max_kk<<endl;
    return 0;
}