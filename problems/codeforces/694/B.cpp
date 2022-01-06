#include <iostream>
#include <cstring>

using namespace std;

long long inputs[100005], process[100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(inputs, 0, sizeof inputs);
        memset(process, 0, sizeof process);
        int n, x;
        cin>>n>>x;
        long long ans=0;
        for (int i=0;i<n;i++) {
            cin>>inputs[i];
            ans+=inputs[i];
            process[i]=inputs[i];
        }
        bool ok=true;
        while (ok){
            for (int i=0;i<n;i++){
                if (process[i]%x!=0) {
                    ok=false;
                    break;
                }
                process[i]/=x;
                ans+=inputs[i];
            }
        }
        cout<<ans<<endl;
    }
}