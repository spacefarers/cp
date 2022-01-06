#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int zero=0, one=0, two=0;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            a%=3;
            if (a==0) zero++;
            else if (a==1) one++;
            else two++;
        }
        int ans=0;
        if (zero>n/3){
            int u=zero-n/3;
            one+=u;
            zero-=u;
            ans+=u;
        }
        if (one>n/3){
            int u=one-n/3;
            two+=u;
            one-=u;
            ans+=u;
        }
        if (two>n/3){
            int u=two-n/3;
            zero+=u;
            two-=u;
            ans+=u;
        }
        if (zero>n/3){
            int u=zero-n/3;
            one+=u;
            zero-=u;
            ans+=u;
        }
        if (one>n/3){
            int u=one-n/3;
            two+=u;
            one-=u;
            ans+=u;
        }
        if (two>n/3){
            int u=two-n/3;
            zero+=u;
            two-=u;
            ans+=u;
        }
        if (zero>n/3){
            int u=zero-n/3;
            one+=u;
            zero-=u;
            ans+=u;
        }
        if (one>n/3){
            int u=one-n/3;
            two+=u;
            one-=u;
            ans+=u;
        }
        if (two>n/3){
            int u=two-n/3;
            zero+=u;
            two-=u;
            ans+=u;
        }
        cout<<ans<<endl;
    }
}