#include <iostream>

using namespace std;

bool gone_bad[1000005];

int main(){
    int n, k;
    string c;
    cin>>n>>k>>c;
    int last_bad=-0x7fffffff;
    for (int i=0;i<n;i++){
        if (c[i]=='*') last_bad=i;
        if (last_bad+k>=i) gone_bad[i]=true;
    }
    last_bad=0x7fffffff;
    for (int i=n-1;i>=0;i--){
        if (c[i]=='*') last_bad=i;
        if (last_bad-k<=i) gone_bad[i]=true;
    }
    for (int i=0;i<n;i++){
        if (gone_bad[i]) cout<<"*";
        else cout<<".";
    }
}