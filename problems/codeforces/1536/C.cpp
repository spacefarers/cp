#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int prefix[500005];

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        string a;
        cin>>n>>a;
        map<pair<int,int>,int> mp;
        memset(prefix,0,sizeof prefix);
        for (int i=1;i<=n;i++){
            prefix[i]=prefix[i-1];
            if (a[i-1]=='D') prefix[i]++;
        }
        for (int i=1;i<=n;i++){
            int ds=prefix[i];
            int ks=i-ds;
            int div=gcd(ds,ks);
            ds/=div;
            ks/=div;
            cout<<++mp[make_pair(ds,ks)]<<" ";
        }
        cout<<endl;
    }
}