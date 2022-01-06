#include <iostream>
#include <cstring>

using namespace std;

bool reach[100];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n, d;
        cin>>n>>d;
        memset(reach, false, sizeof reach);
        reach[0]=true;
        for (int i=1;i<=d*11;++i){
            for (int k=0;k<10;++k){
                int j=k*10+d;
                if (i-j>=0&&reach[i-j]) reach[i]=true;
            }
            for (int k=0;k<10;++k){
                int j=d*10+k;
                if (i-j>=0&&reach[i-j]) reach[i]=true;
            }
        }
        for (int i=0;i<n;++i){
            int a;
            cin>>a;
            if (a>d*11||reach[a]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}