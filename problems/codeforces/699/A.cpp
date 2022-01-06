#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int px, py;
        string s;
        cin>>px>>py>>s;
        int rs=0, us=0, ds=0, ls=0;
        for (auto &i:s){
            switch (i){
                default:
                    break;
                case 'R':
                    rs++;
                    break;
                case 'U':
                    us++;
                    break;
                case 'D':
                    ds++;
                    break;
                case 'L':
                    ls++;
                    break;
            }
        }
        if (px<-ls||px>rs||py<-ds||py>us) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}