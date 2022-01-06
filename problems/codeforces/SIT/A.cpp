#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int a, b, c;
        cin>>a>>b>>c;
        if (a*b!=c){
            swap(a, c);
            if (a*b!=c){
                swap(b, c);
                if (a*b!=c){
                    cout<<"NO"<<endl;
                    continue;
                }
            }
        }
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
}