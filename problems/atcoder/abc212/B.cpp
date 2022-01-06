// created on 2021/7/31 by spacefarers
// problem: 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    string x;
    cin>>x;
    if (x[0]==x[1]){
        for (int i=1;i<3;i++){
            if (x[i]!=x[i+1]){
                cout<<"Strong"<<endl;
                goto cont;
            }
        }
    } else if ((x[0]-'0'+1)%10==x[1]-'0'){
        for (int i=1;i<3;i++){
            if ((x[i]-'0'+1)%10!=x[i+1]-'0'){
                cout<<"Strong"<<endl;
                goto cont;
            }
        }
    } else {
        cout<<"Strong"<<endl;
        goto cont;
    }
    cout<<"Weak"<<endl;
    cont:;
}