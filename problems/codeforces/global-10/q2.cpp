#include <iostream>

using namespace std;

int main(){
    int test_cases;
    cin>>test_cases;
    for (int i=0;i<test_cases;i++){
        int n, k;
        cin>>n>>k;
        int a[n];
        for (int j=0;j<n;j++){
            cin>>a[j];
        }
        for (int j=0;j<k;j++){
            int max_num=-0x7fffffff;
            for (int b=0;b<n;b++){
                if (a[b]>max_num) max_num = a[b];
            }
            for (int b=0;b<n;b++){
                a[b] = max_num-a[b];
            }
        }
        for (int j=0;j<n;j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
}
