#include <iostream>

using namespace std;

int main(){
    long long n, last, ans=0;
    cin>>n>>last;
    for (int i=1;i<n;i++){
        long long a;
        cin>>a;
        if (a<last){
            ans+=(last-a);
        } else {
            last = a;
        }
    }
    cout<<ans<<endl;
}