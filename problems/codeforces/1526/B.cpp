#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int x;
        cin>>x;
        int factors=x/11;
        int mod=x%11;
        if (factors<mod*10)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}