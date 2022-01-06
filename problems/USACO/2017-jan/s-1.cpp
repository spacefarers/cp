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

int n, t, cows[100005];
priority_queue<int, vi, greater<int>> times;

bool validate(int x){
    for (int i=0;i<x;i++){
        times.push(0);
    }
    for (int j=0;j<n;j++){
        int e=times.top();
        times.pop();
        e+=cows[j];
        times.push(e);
    }
    int max_v=0;
    while (!times.empty()){
        max_v=max(times.top(), max_v);
        times.pop();
    }
    return max_v<=t;
}

int main() {
    setIO("cowdance");
    cin>>n>>t;
    for (int i=0;i<n;i++){
        cin>>cows[i];
    }
    int left=0, right=n;
    while (left<=right){
        int mid=(left+right+1)/2;
        if (validate(mid)){
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;
}