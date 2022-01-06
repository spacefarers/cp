#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        long long a, b, c=1, ans=0;
        cin>>a>>b;
        while (true){
            long long add_factor=min((a-c)/c, b)-c;
            if (add_factor<=0) break;
            ans+=add_factor;
            c++;
        }
        cout<<ans<<endl;
    }
}