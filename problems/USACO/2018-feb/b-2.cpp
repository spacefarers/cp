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

int N, passto[100], x[100];

int target(int i)
{
    int left_nbr=-1, left_dist = 1000;
    int right_nbr=-1, right_dist = 1000;

    // Find closet neighbors on left and right
    for (int j=0; j<N; j++)
        if (x[j] < x[i] && x[i]-x[j] < left_dist) { left_nbr = j; left_dist = x[i]-x[j]; }
    for (int j=0; j<N; j++)
        if (x[j] > x[i] && x[j]-x[i] < right_dist) { right_nbr = j; right_dist = x[j]-x[i]; }

    if (left_dist <= right_dist) return left_nbr;
    return right_nbr;
}


int main() {
    setIO("hoofball");
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>x[i];
    }
    for (int i=0;i<N;i++){
        passto[target(i)]++;
    }
    int ans=0;
    for (int i=0;i<N;i++){
        if (passto[i]==0) ans++;
        if (i<target(i)&&target(target(i))==i&&passto[i]==1&&passto[target(i)]==1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}