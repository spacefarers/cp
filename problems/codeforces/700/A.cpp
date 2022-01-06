#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        bool alice=true;
        for (auto &i:a){
            if (alice){
                if (i=='a') i='b';
                else i='a';
            } else {
                if (i=='z') i='y';
                else i='z';
            }
            alice=!alice;
        }
        cout<<a<<endl;
    }
}