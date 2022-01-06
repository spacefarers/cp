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
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n, last_instance=0, last=-1;
vi values, sort_n, sorted;

int main() {
    setIO("sleepy");
    cin>>n;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        values.pb(a);
        if (last>a) last_instance=i-1;
        last=a;
    }
    cout<<last_instance<<endl;
    for (int i=0;i<n;i++){
        if (i<last_instance)
            sort_n.pb(values[i]);
        else
            sorted.pb(values[i]);
    }
    while (!sort_n.empty()){
        int e=sort_n[0];
        sort_n.erase(sort_n.begin());
        int left=0, right=sorted.size();
        while (left<right) {
//            cout<<left<<" "<<right<<endl;
            int mid=left+(right-left)/2;
            if (sorted[mid]>e)
                if (right==mid)
                    right=mid-1;
                else
                    right=mid;
            else
                if (left==mid)
                    left=mid+1;
                else
                    left=mid;
        }
        sorted.insert(sorted.begin()+left, e);
//        cout<<left<<endl;
        cout<<sort_n.size()+left<<((sort_n.empty())?"":" ");
    }

    return 0;
}