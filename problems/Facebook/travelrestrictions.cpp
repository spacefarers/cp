#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

int forwards[1000], backwards[1000];

int main() {
    int t;
    cin>>t;
    for (int k=1;k<=t;k++){
        cout<<"Case #"+to_string(k)+":"<<endl;
        memset(forwards, -1, sizeof forwards);
        memset(backwards, -1, sizeof backwards);
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        int counts=0;
        for (int i=0;i<n;i++){
            if (i>0&&(a[i]=='N'||b[i-1]=='N')) counts++;
            forwards[i]=counts;
        }
        for (int i=n-1;i>=0;i--){
            if (i<n-1&&(a[i]=='N'||b[i+1]=='N')) counts++;
            backwards[i]=counts;
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i>j){
                    if (backwards[i]==backwards[j]) cout<<"Y";
                    else cout<<"N";
                } else if (i<j){
                    if (forwards[i]==forwards[j]) cout<<"Y";
                    else cout<<"N";
                } else {
                    cout<<"Y";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}