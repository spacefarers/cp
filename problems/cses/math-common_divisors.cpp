#include <iostream>

using namespace std;

int counts[1000005];

int main(){
    int n;
    cin>>n;
    int max_num=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        counts[a]++;
        max_num=max(max_num, a);
    }
    for (int i=max_num;i>=1;i--){
        int c=0;
        for (int j=i;j<=max_num;j+=i) c+=counts[j];
        if (c>1){
            cout<<i<<endl;
            break;
        }
    }
}