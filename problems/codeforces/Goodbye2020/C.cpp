#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        string a;
        cin>>a;
        int ans=0;
        for (int i=0;i<a.size();i++){
            if ((i>1&&a[i]==a[i-2])||(i>0&&a[i]==a[i-1])){
                ans++;
                for (char new_one='a';new_one<='z';new_one++){
                    if (new_one!=a[i-1]&&new_one!=a[i+1]&&new_one!=a[i-2]&&new_one!=a[i+2]){
                        a[i]=new_one;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}