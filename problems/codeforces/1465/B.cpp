#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        long long a;
        cin>>a;
        while (true){
            string b=to_string(a);
            bool ok=true;
            for (auto &i:b){
                if (i=='0') continue;
                if (a%(i-'0')!=0){
                    ok=false;
                    break;
                }
            }
            if (ok) break;
            a++;
        }
        cout<<a<<endl;
    }
}