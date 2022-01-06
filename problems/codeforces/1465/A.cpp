#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        string a;
        cin>>n>>a;
        reverse(a.begin(), a.end());
        int ans=0;
        for (auto &i:a){
            if (i==')') ans++;
            else break;
        }
        if (2*ans>n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}