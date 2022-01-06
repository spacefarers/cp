#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
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

map<string, int> mp;

int main() {
    setIO("notlast");
    int n;
    cin>>n;
    mp["Bessie"]=0;
    mp["Elsie"]=0;
    mp["Daisy"]=0;
    mp["Gertie"]=0;
    mp["Annabelle"]=0;
    mp["Maggie"]=0;
    mp["Henrietta"]=0;
    for (int i=0;i<n;i++){
        string a;
        int b;
        cin>>a>>b;
        mp[a]+=b;
    }
    int min_v=0x7fffffff;
    trav (i, mp){
        min_v=min(min_v, i.second);
    }
    int second_min=0x7fffffff, c=0;
    string winner;
    trav (i, mp){
        if (i.second>min_v){
            if (i.second<second_min) {
                c=1;
                winner=i.first;
                second_min=i.second;
            } else if (i.second==second_min){
                c++;
            }
        }
    }
//    cout<<second_min<<endl;
    if (c==0||c>1) cout<<"Tie"<<endl;
    else cout<<winner<<endl;
    return 0;
}