#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n, x;
        cin>>n>>x;
        long long ans=0, all_sum=0;
        for (int i=0;i<n;i++){
            long long a;
            cin>>a;
            ans+=a/x;
            if (a%x!=0) ans++;
            all_sum+=a;
        }
        long long min_ans=all_sum/x;
        if (all_sum%x!=0) min_ans++;
        cout<<min_ans<<" "<<ans<<endl;
    }
}