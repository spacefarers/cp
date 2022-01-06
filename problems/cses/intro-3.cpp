#include <iostream>

using namespace std;

int main(){
    string a;
    cin>>a;
    int last_same=0, ans=0;
    for (int i=0;i<a.size();i++){
        if (a[last_same]!=a[i]){
            ans=max(ans, i-last_same);
            last_same=i;
        }
    }
    ans=max(ans, (int)(a.size()-last_same));
    cout<<ans<<endl;
}