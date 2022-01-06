#include <iostream>

using namespace std;

int main(){
    long long q;
    cin>>q;
    for (int i=0;i<q;i++){
        long long a, b;
        cin>>a>>b;
        long long x=max(a, b);
        long long num=x*(x-1)+1;
        cout<<num-((x%2==0)?(b-a):(a-b))<<endl;
    }
}