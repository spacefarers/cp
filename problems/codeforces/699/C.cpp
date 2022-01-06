#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> debt[100005];
int ans[100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(ans, 0, sizeof ans);
        int n, m;
        cin>>n>>m;
        vector<int> initial(n), desire(n), painters(m);
        for (auto &i:debt){
            i.clear();
        }
        for (int i=0;i<n;i++){
            cin>>initial[i];
        }
        for (int i=0;i<n;i++){
            cin>>desire[i];
            if (initial[i]!=desire[i]) debt[desire[i]].push_back(i+1);
        }
        for (int i=0;i<m;i++){
            cin>>painters[i];
        }
        int f_pos=0;
        if (!debt[painters[m-1]].empty()){
            f_pos=debt[painters[m-1]].back();
            debt[painters[m-1]].pop_back();
        } else {
            for (int i=0;i<n;i++){
                if (desire[i]==painters[m-1]){
                    f_pos=i+1;
                    break;
                }
            }
        }
        if (!f_pos){
            cout<<"NO"<<endl;
            continue;
        }
        ans[m-1]=f_pos;
        for (int i=0;i<m-1;i++){
            if (!debt[painters[i]].empty()){
                ans[i]=debt[painters[i]].back();
                debt[painters[i]].pop_back();
            } else {
                ans[i]=f_pos;
            }
        }
        bool ok=true;
        for (auto &i:debt){
            if (!i.empty()) ok=false;
        }
        if (!ok){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for (int i=0;i<m;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}