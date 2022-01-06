#include <iostream>

using namespace std;

int main(){
    long long m;
    cin>>m;
    for (long long i=1;i<=m;i++){
        cout<<i*i*(i*i-1)/2-(i-1)*(i-2)*4<<endl;
    }
}