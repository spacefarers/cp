#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

ll roundup(double a){
    ll b=floor(a);
    if (a-(double)b>1e-6) b++;
    return b;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        ll p, a, b, c;
        cin>>p>>a>>b>>c;
        ll next_a=(a-p%a)%a;
        ll next_b=(b-p%b)%b;
        ll next_c=(c-p%c)%c;
        cout<<min(min(next_a, next_b), next_c)<<endl;
    }
}