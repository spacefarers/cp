#include <iostream>

using namespace std;

int main(){
    int test_cases;
    cin>>test_cases;
    for (int cases=1;cases<=test_cases;cases++){
        long long n;
        cin>>n;
        long long count=0, ans=0;
        for (int i=1;i<=n;i++){
            int a;
            cin>>a;
            if (a<0){
                if (count>0) {
                    count+=a;
                    if (count<0){
                        ans-=count;
                        count=0;
                    }
                } else {
                    ans-=a;
//                    count+=a;
                }
            } else {
                count+=a;
            }
        }
        cout<<ans<<endl;
    }
}