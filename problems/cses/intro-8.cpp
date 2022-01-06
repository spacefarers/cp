#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n;
    cin>>n;
    if (((1+n)*n/2)%2==0){
        cout<<"YES"<<endl;
        long long ans=((1+n)*n/2)/2;
        vector<long long> ans1;
        for (int i=n;i>=1;i--){
            if (ans>=i) {
                ans-=i;
                ans1.push_back(i);
            }
        }
        cout<<ans1.size()<<endl;
        for (auto &a:ans1){
            cout<<a<<" ";
        }
        cout<<endl<<n-ans1.size()<<endl;
        int c=0;
        for (int i=n;i>=1;i--){
            if (ans1[c]==i) {
                c++;
                continue;
            }
            cout<<i<<" ";
        }
    } else {
        cout<<"NO"<<endl;
    }
}