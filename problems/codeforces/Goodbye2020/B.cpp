#include <iostream>
#include <cstring>

using namespace std;

bool used[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(used, false, sizeof used);
        int n;
        cin>>n;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            if (used[a]) used[a+1]=true;
            else used[a]=true;
        }
        int ans=0;
        for (bool i:used){
            if (i) ans++;
        }
        cout<<ans<<endl;
    }
}