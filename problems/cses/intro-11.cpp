#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    while (n--){
        long long a, b;
        cin>>a>>b;
        long long dif=abs(a-b);
        if (a+b>=dif*3&&(a+b)%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}