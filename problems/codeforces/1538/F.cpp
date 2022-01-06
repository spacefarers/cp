#include <iostream>

using namespace std;

int solve(int x){
    int ans=0;
    while (x!=0){
        ans+=x;
        x/=10;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int a,b;
        cin>>a>>b;
        cout<<solve(b)-solve(a)<<endl;
    }
}