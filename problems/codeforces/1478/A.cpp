#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1005];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(a, 0, sizeof a);
        int n;
        cin>>n;
        for (int i=0;i<n;++i){
            int c;
            cin>>c;
            a[c]++;
        }
        cout<<*max_element(a, a+105)<<endl;
    }
}