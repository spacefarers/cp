#include <iostream>

using namespace std;

int main(){
    int n, modd=(1e9+7);
    cin>>n;
    long long ans=1;
    for (int i=0;i<n;i++){
        ans*=2;
        ans%=modd;
    }
    cout<<ans<<endl;
}