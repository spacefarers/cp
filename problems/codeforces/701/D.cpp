#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int b;
            cin>>b;
            if ((i+j)%2) cout<<720720+pow(b, 4)<<" ";
            else cout<<720720<<" ";
        }
        cout<<endl;
    }
}