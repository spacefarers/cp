#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        long long n;
        cin>>n;
        long long a=n/2, b=n-n/2;
        cout<<(a+1)*(b+1)<<endl;
    }
}