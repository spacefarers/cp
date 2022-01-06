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
vi logs;

int main() {
    setIO("taming");
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        logs.pb(a);
    }
    int knowledge=0;
    for (int i=n-1;i>=0;i--){
        if (knowledge>0){
            if (logs[i]==-1){
                logs[i]=--knowledge;
            } else if (logs[i]!=--knowledge){
                cout<<-1<<endl;
                return 0;
            }
        } else if (logs[i]!=-1){
            knowledge=logs[i];
        }
    }
    if (logs[0]!=-1&&logs[0]!=0){
        cout<<-1<<endl;
        return 0;
    }
    logs[0]=0;
    int min_ans=0, max_ans=0;
    for (int i=0;i<n;i++){
        if (logs[i]==0){
            min_ans++;
            max_ans++;
        } else if (logs[i]==-1){
            max_ans++;
        }
    }
    cout<<min_ans<<" "<<max_ans<<endl;
    return 0;
}