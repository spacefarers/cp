#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
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
map<string, int> traits;
map<int, string> traits_rev;
vi pop[30];
bool has_trait[50][50];
bool visited[3000];
bool stop=false;
int times[30];
int id[30];
map<int, int, greater<int>> sorted_traits;

bool cmp(int x, int y){
    return times[x]>times[y];
}

void search(const vi &search_on){
    if (search_on.empty()||stop) return;
    memset(times, 0, sizeof(times));
    trav(i, search_on){
        trav(j, pop[i]){
            times[j]++;
        }
    }
    for (int i=0;i<30;i++){
        id[i]=i;
    }
    sort(id, id+30, cmp);
    int l_n = id[0];
    if (times[l_n]==0) return;
//    cout<<l_n<<endl;
//    trav(j, search_on) cout<<j<<" ";
//    cout<<endl;
    if (visited[l_n]){
        cout<<"no"<<endl;
        stop=true;
    }
    visited[l_n]=true;
    vi new_search_on, new_excluded;
    trav (i, search_on){
//        trav(j, pop[i]) cout<<j<<" ";
//        cout<<endl;
        if (has_trait[i][l_n]) {
            new_search_on.pb(i);
            has_trait[i][l_n]=false;
            pop[i].erase(remove(all(pop[i]), l_n), pop[i].end());
        }
        else new_excluded.pb(i);
    }
    search(new_search_on);
    if (stop) return;
    search(new_excluded);
}

int main() {
    setIO("evolution");
    cin>>n;
    int c=1;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        for (int j=1;j<=a;j++){
            string b;
            cin>>b;
            if (traits[b]==0) {
                traits[b]=c++;
                traits_rev[c]=b;
            }
            pop[i].pb(traits[b]);
            has_trait[i][traits[b]]=true;
        }
    }
    vi search_on;
    for (int i=1;i<=n;i++) {
        search_on.pb(i);
    }
    search(search_on);
    if (!stop) cout<<"yes"<<endl;
    return 0;
}