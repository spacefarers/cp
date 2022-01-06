/*
ID: michael419
LANG: C++
TASK: subset
*/

#include <iostream>
#include <vector>

using namespace std;

#define f first
#define s second

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

long long ways[1000];

int main(){
    setIO("subset");
    int n;
    cin>>n;
    if ((1+n)*n/2%2) {
        cout<<0<<endl;
        exit(0);
    }
    int target=(1+n)*n/4;
    ways[0]=1;
    for (int j=1;j<=n;j++){
        for (int i=target;i>=1;i--){
            if (i-j>=0) ways[i]+=ways[i-j];
        }
    }
    cout<<ways[target]/2<<endl;
}