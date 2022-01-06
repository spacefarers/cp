#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n, k;
        cin>>n>>k;
        vector<int> mountains(n);
        for (int i=0;i<n;i++) cin>>mountains[i];
        if (n==1) {
            cout<<-1<<endl;
            continue;
        }
        int ans=-2;
        while (true){
            for (int i=0;i<n-1;i++){
                if (mountains[i+1]>mountains[i]){
                    k--;
                    mountains[i]++;
                    if (k<=0) ans=i+1;
                    break;
                }
                if (i==n-2) ans=-1;
            }
            if (ans!=-2) break;
        }
        cout<<ans<<endl;
    }
}