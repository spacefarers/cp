#include <iostream>
#include <cstring>

using namespace std;

string u;
int n;
bool ok=false;

long long poww(int a, int b){
    long long ans=1;
    for (int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

void solve(){
    if (ok) return;
    if (u.size()==n){
        if (stoll(u)%poww(2, n)==0){
            cout<<u<<endl;
            ok=true;
        }
        return;
    }
    u+='1';
    solve();
    u=u.substr(0, u.size()-1);
    u+='2';
    solve();
    u=u.substr(0, u.size()-1);
}

int main(){
    cin>>n;
    ok=false;
    u="";
    solve();
    if (!ok) cout<<-1<<endl;
}