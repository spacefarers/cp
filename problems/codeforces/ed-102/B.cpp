#include <iostream>

using namespace std;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        string a, b;
        cin>>a>>b;
        string working, working2;
        for (int i=0;i<lcm(a.size(), b.size())/a.size();i++){
            working+=a;
        }
        for (int i=0;i<lcm(a.size(), b.size())/b.size();i++){
            working2+=b;
        }
        if (working==working2) cout<<working<<endl;
        else cout<<-1<<endl;
    }
}
