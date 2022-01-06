#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        long long a, b, c;
        a=(n/5);
        b=(n/3-n/15);
        c=(n/2-n/10-n/6+n/30);
        cout<<a*5+b*3+c*2+n-a-b-c<<endl;
    }
}