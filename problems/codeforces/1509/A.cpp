#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> singles;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            if (a%2) singles.push_back(a);
            else cout<<a<<" ";
        }
        for (auto i:singles){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}