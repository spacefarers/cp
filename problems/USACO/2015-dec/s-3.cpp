//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstring>
//#include <queue>
//#include <set>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int,int> pi;
//typedef pair<ll,ll> pl;
//typedef vector<pi> vpi;
//typedef vector<pl> vpl;
//typedef vector<vi> vvi;
//typedef vector<vl> vvl;
//
//#define trav(a,x) for (auto& a: x)
//
//#define pb push_back
//#define rsz resize
//#define sz(x) int(x.size())
//#define all(x) begin(x), end(x)
//#define f first
//#define s second
//
//
//void setIO(const string& name) {
//    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    freopen((name+".in").c_str(),"r",stdin);
//    freopen((name+".out").c_str(),"w",stdout);
//}
//
//int tree[100005][3], inputs[100005], temp[3];
//
//void build_tree(int node, int start, int end){
//    if (start==end) tree[node][inputs[start]-1]=1;
//    else {
//        int mid=(start+end)/2;
//        build_tree(2*node, start, mid);
//        build_tree(2*node+1, mid+1, end);
//        tree[node][0]=tree[2*node][0]+tree[2*node+1][0];
//        tree[node][1]=tree[2*node][1]+tree[2*node+1][1];
//        tree[node][2]=tree[2*node][2]+tree[2*node+1][2];
//    }
//}
//
//int* query(int node, int start, int end, int l, int r){
//    if (l>r) return temp;
//    if (l==start and r==end) return tree[node];
//    int mid=(start+end)/2;
//    auto p1=query(2*node, start, mid, l, min(r, mid));
//    auto p2=query(2*node+1, mid+1, end, max(l, mid+1), r);
//    p1[0]+=p2[0];
//    p1[1]+=p2[1];
//    p1[2]+=p2[2];
//    return p1;
//}
//
//int main() {
////    setIO("");
//    int n, q;
//    cin>>n>>q;
//    for (int i=0;i<n;i++){
//        cin>>inputs[i];
//    }
//    build_tree(1, 0, n-1);
//    for (int i=0;i<q;i++){
//        int a, b;
//        cin>>a>>b;
//        auto ans=query(1, 0, n-1, a-1, b-1);
//        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
//    }
//    return 0;
//}

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


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int sums[100005][3];
int main() {
    setIO("bcount");
    int n, q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        sums[i][a-1]=1;
        sums[i][0]+=sums[i-1][0];
        sums[i][1]+=sums[i-1][1];
        sums[i][2]+=sums[i-1][2];
    }
    for (int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;
        auto x=sums[a-1];
        auto y=sums[b];
        cout<<y[0]-x[0]<<" "<<y[1]-x[1]<<" "<<y[2]-x[2]<<endl;
    }
    return 0;
}