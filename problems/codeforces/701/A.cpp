#include <iostream>

using namespace std;

int a, b;

int solve(int x){
    if (b+x<=1) return 0x7fffffff;
    int u=a, ans=0;
    while (u!=0){
        ans++;
        u/=(b+x);
    }
    return ans+x;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>a>>b;
        if (a==0){
            cout<<0<<endl;
            continue;
        }
        int added=b==1;
        if (added) b++;
        int ans=0x7fffffff;
        for (int i=0;i<1000;i++){
            ans=min(ans, solve(i));
        }
        cout<<ans+added<<endl;
    }
}