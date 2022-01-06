// created on 2021/7/3 by spacefarers
// problem: B. Plus and Multiply

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll poww(int a,int b){
    ll ans=1;
    for (int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,a,b;
        cin>>n>>a>>b;
        bool ans=false;
        if (a==1){
            if ((n-1)%b) ans=false;
            else ans=true;
        } else {
            for (int i=0;poww(a,i)<=n;i++){
                if ((n-poww(a,i))%b==0) ans=true;
            }
        }
        if (ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}