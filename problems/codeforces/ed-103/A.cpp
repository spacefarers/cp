#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        long long n, k;
        cin>>n>>k;
        k=(long long)ceil((double)n/(double)k)*k;
        k=(long long)ceil((double)k/(double)n);
        cout<<k<<endl;
    }
}