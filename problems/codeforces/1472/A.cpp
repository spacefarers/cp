#include <iostream>
#include <vector>

using namespace std;

int poww(int a, int b){
    int ans=1;
    for (int i=0;i<b;++i){
        ans*=a;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int w, h, n;
        cin>>w>>h>>n;
        int c1=0;
        while (w%poww(2, c1+1)==0) c1++;
        int c2=0;
        while (h%poww(2, c2+1)==0) c2++;
        if (poww(2, c1)*poww(2, c2)>=n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}