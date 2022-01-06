#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        ll left=0;
        cin>>n;
        bool ok=true;
        for (ll i=0;i<n;i++){
            ll a;
            cin>>a;
            if (!ok) continue;
            if (a>=i) left+=(a-i);
            else if (a+left>=i) left-=(i-a);
            else {
                cout<<"NO"<<endl;
                ok=false;
            }
        }
        if (ok) cout<<"YES"<<endl;
    }
}