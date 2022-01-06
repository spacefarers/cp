#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if (n==1) cout<<1<<endl;
    else if (n==4) cout<<"2 4 1 3"<<endl;
    else if (n<5) cout<<"NO SOLUTION"<<endl;
    else {
        int i=1;
        while (i<=n){
            cout<<i<<" ";
            i+=2;
        }
        i=2;
        while (i<=n){
            cout<<i<<" ";
            i+=2;
        }
    }
}