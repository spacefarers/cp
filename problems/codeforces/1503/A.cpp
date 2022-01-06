// created on 2021/7/3 by spacefarers
// problem: A. Balance the Bits

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        string x;
        cin>>x;
        int ones=0;
        for (auto i:x){
            if (i=='1') ones++;
        }
        if (x[0]!='1'||x[n-1]!='1'||n%2||ones%2){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            string a=x,b=x;
            int c=0,d=0;
            for (int i=0;i<n;i++){
                if (x[i]=='1'){
                    if (c++<ones/2)
                        a[i]=b[i]='(';
                    else a[i]=b[i]=')';
                } else {
                    a[i]='(',b[i]=')';
                    if (d++%2) swap(a[i],b[i]);
                }
            }
            cout<<a<<endl<<b<<endl;
        }
    }
}