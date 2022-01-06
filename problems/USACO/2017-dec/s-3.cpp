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
typedef vector<pair<int,int>> vpi;

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

int n, pos[100005];
vi list;
bool visited[100005], determined[100005], ans[100005];
bool start=false;

void find(int x, int y, int dep){
    cout<<list.size()<<endl;
    if (determined[x]){
        trav (i, list){
            determined[i]=true;
            ans[i]=false;
        }
    }
    if (visited[x]) {
        determined[y]=true;
        ans[y]=false;
        start=false;
        trav(i, list){
            if (i==x){
                start=true;
            }
            if (start){
                determined[i]=true;
                ans[i]=true;
            } else {
                determined[i]=true;
                ans[i]=false;
            }
        }
        return;
    }
    if (dep!=0&&x==y){
        trav (i, list){
            determined[i]=true;
            ans[i]=true;
        }
        return;
    }
    list.pb(x);
    visited[x]=true;
    find(pos[x], y, dep+1);
}

int main() {
    setIO("shuffle");
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>pos[i];
    }
//    n=100000;
//    pos[1]=n;
//    for (int i=2;i<=n;i++){
//        pos[i]=i-1;
//    }
    for (int i=1;i<=n;i++){
        if (!determined[i]){
            list.clear();
            memset(visited, false, sizeof(visited));
//            find(i, i, 0);
            int c_item=i;
            while (true){
                if (determined[c_item]){
                    trav(u, list){
                        determined[u]=true;
                        ans[u]=false;
                    }
                    break;
                }
                if (visited[c_item]) {
                    start=false;
                    trav(u, list){
                        if (u==c_item){
                            start=true;
                        }
                        determined[u]=true;
                        ans[u]=start;
                    }
                    break;
                }
                visited[c_item]=true;
                list.pb(c_item);
                c_item=pos[pos[c_item]];
            }
        }
    }
    int f_ans=0;
    for (int i=1;i<=n;i++){
//        cout<<i<<" "<<pos[i]<<endl;
        if (ans[i]) {
//            cout<<i<<endl;
            f_ans++;
        }
    }
    cout<<f_ans<<endl;
    return 0;
}