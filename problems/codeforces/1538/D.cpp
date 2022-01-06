#include <iostream>

using namespace std;

int prime_fact(int a){
    int ans=0;
    while (a%2==0){
        ans++;
        a/=2;
    }
    for (int i=3;i*i<=a;i+=2){
        while (a%i==0){
            ans++;
            a/=i;
        }
    }
    if (a!=1) ans++;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int a,b,k;
        cin>>a>>b>>k;
        if (a>b) swap(a,b);
        if (k==1){
            if (b%a||a==b) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        if (prime_fact(a)+prime_fact(b)>=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}