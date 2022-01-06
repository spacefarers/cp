// Digit Queries

#include <iostream>

#define ll long long

using namespace std;

ll poww(ll a, ll b){
    ll ans=1;
    for (int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

ll getlength(ll x){
    string a=to_string(x);
    ll prev_size=(ll)a.size()-1;
    ll prev_counts=0, prev_nums=0;
    while (prev_size){
        prev_counts+=poww(10, prev_size-1)*9*prev_size;
        prev_nums+=poww(10, prev_size-1)*9;
        prev_size--;
    }
    return prev_counts+(x-prev_nums)*(ll)a.size();
}

int main(){
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        ll x;
        cin>>x;
        ll z=0, j;
        for (j=1e15;j>=1;j/=2){
            while (getlength(z+j)<x) z+=j;
        }
        z+=1;
        string u=to_string(z);
        cout<<u[u.size()-getlength(z)+x-1]<<endl;
    }
}