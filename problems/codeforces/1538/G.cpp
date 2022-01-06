#include <iostream>

using namespace std;

long long x,y,a,b;
int validate(long long pieces){
    (x-a*pieces)
}

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>x>>y>>a>>b;
        long long z=-1;
        for (long long i=1e9;i>=1;i/=2){
            if (a*i>x||b*i>y) continue;
            while (validate(z+i)>validate(z+i+1)) z+=i;
        }
        cout<<
    }
}