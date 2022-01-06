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
vpi a, b;

int main() {
    setIO("lifeguards");
    cin>>n;
    a.rsz(n);
    for (int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(all(a));
    int rem=-1;
    for (int i=0;i<n;i++){
        if (i==0){
            if (a[i].second<a[i+1].first) b.pb({a[i].second-a[i].first, i});
            else {
                if (a[i].second>a[i+1].second) {
                    rem=i+1;
                    break;
                }
                b.pb({a[i+1].first-a[i].first, i});
            }
        } else if (i==n-1){
            if (a[i-1].second<a[i].first) b.pb({a[i].second-a[i].first, i});
            else {
                if (a[i].second<a[i-1].second) {
                    rem=i;
                    break;
                }
                b.pb({a[i].second-a[i-1].first, i});
            }
        } else {
            if (a[i-1].second<a[i].first&&a[i].second<a[i+1].first) b.pb({a[i].second-a[i].first, i});
            if (a[i-1].second>=a[i+1].first) {
                rem=i;
                break;
            }
            if (a[i-1].second<a[i].first){
                b.pb({a[i+1].first-a[i].first, i});
            } else if (a[i].second<a[i+1].first){
                b.pb({a[i].second-a[i-1].second, i});
            } else {
                b.pb({a[i+1].first-a[i-1].second, i});
            }
        }
    }
    if (rem==-1) {
        sort(all(b));
        rem=b[0].second;
    }
    int c_ans=0;
    int c_pos=0;
    for (int j=0;j<n;j++){
        if (rem==j) continue;
        if (c_pos>=a[j].first){
            if (c_pos<=a[j].second){
                c_ans+=a[j].second-c_pos;
                c_pos=a[j].second;
            } else
                continue;
        } else if (c_pos<a[j].first){
            c_ans+=a[j].second-a[j].first;
            c_pos=a[j].second;
        }
    }
    cout<<c_ans<<endl;
    return 0;
}