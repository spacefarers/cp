#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    if ((a-b)*(a-c)>=0) cout<<max(abs(a-b), abs(a-c))<<endl;
    else cout<<min(abs(a-b)*2+abs(a-c), abs(a-c)*2+abs(a-b))<<endl;
}