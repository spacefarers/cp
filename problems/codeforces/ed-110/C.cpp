#include <iostream>

using namespace std;

long long calc(long long x){
    return (x+1)*x/2;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        string a;
        cin>>a;
        long long c=0,ans=0,qs=0;
        bool determined=false,current=false;
        for (int i=0;i<a.size();i++){
            if (determined){
                current=!current;
                if (a[i]!='?'&&current!=a[i]-'0'){
                    ans+=calc(c);
                    c=qs;
                    determined=false;
                    ans-=calc(qs);
                    i--;
                    continue;
                } else if (a[i]=='?') qs++;
                else {
                    qs=0;
                }
            } else {
                if (a[i]!='?'){
                    determined=true;
                    current=a[i]-'0';
                    qs=0;
                } else qs++;
            }
            c++;
        }
        ans+=calc(c);
        cout<<ans<<endl;
    }
}