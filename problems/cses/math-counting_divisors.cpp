#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        long long ans=0;
        for (int i=1;i<=sqrt(n);i++){
            if (n%i==0) ans+=2;
            if (n%i==0&&n/i==i) ans--;
        }
        cout<<ans<<endl;
    }

}