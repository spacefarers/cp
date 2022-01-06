#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int> queries;

int ask(int a, int b){
    if (a>b) swap(a, b);
    if (queries[{a, b}]!=0) return queries[{a, b}];
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    int ans;
    cin>>ans;
    queries[{a, b}]=ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int num2=ask(1, n);
    bool type_left_ok=true;
    if (num2==1) type_left_ok=false;
    else if (num2==n) type_left_ok=true;
    else {
        int resp1=ask(1, num2);
        type_left_ok=resp1==num2;
    }
    int z;
    if (type_left_ok){
        int l=1;
        int r=num2;
        while (r-l>1){
            int m=(l+r)/2;
            if (ask(m, num2)==num2) l=m;
            else r=m;
        }
        cout<<"! "<<l<<endl;
    } else {
        int l=num2;
        int r=n;
        while (r-l>1){
            int m=(l+r)/2;
            if (ask(m, num2)==num2) r=m;
            else l=m;
        }
        cout<<"! "<<r<<endl;
    }
    cout.flush();
}