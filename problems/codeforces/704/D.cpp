#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a, b, k;
    cin>>a>>b>>k;
    int max_num=a+b-2;
    if (a==0||b==1) max_num=0;
    if (k>max_num){
        cout<<"NO"<<endl;
        exit(0);
    }
    cout<<"YES"<<endl;
    if (k==0){
        for (int i=0;i<b;i++){
            cout<<1;
        }
        for (int i=0;i<a;i++){
            cout<<0;
        }
        cout<<endl;
        for (int i=0;i<b;i++){
            cout<<1;
        }
        for (int i=0;i<a;i++){
            cout<<0;
        }
        cout<<endl;
        exit(0);
    }
    vector<int> same;
    same.reserve(b+a-2);
    for (int i=0;i<b-1;i++){
        same.push_back(1);
    }
    for (int i=0;i<a-1;i++){
        same.push_back(0);
    }
    for (int i=0;i<a+b-2-k+1;i++){
        cout<<same[i];
    }
    cout<<1;
    for (int i=a+b-2-k+1;i<a+b-2;i++){
        cout<<same[i];
    }
    cout<<0;
    cout<<endl;
    for (int i=0;i<a+b-2-k+1;i++){
        cout<<same[i];
    }
    cout<<0;
    for (int i=a+b-2-k+1;i<a+b-2;i++){
        cout<<same[i];
    }
    cout<<1;
    cout<<endl;
}