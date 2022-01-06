/*
ID: michael419
LANG: C++
TASK: msquare
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vector<int> config(8), target(8);

void op_A(){
    swap(config[0], config[4]);
    swap(config[1], config[5]);
    swap(config[2], config[6]);
    swap(config[3], config[7]);
}

void op_B(){
    int temp1=config[0], temp2=config[4];
    config[0]=config[3];
    config[3]=config[2];
    config[2]=config[1];
    config[1]=temp1;
    config[4]=config[7];
    config[7]=config[6];
    config[6]=config[5];
    config[5]=temp2;
}

void op_C(){
    int temp=config[1];
    config[1]=config[5];
    config[5]=config[6];
    config[6]=config[2];
    config[2]=temp;
}

string temp;

void solve(int x){
    if (temp.size()==x){
        if (config==target){
            cout<<temp.size()<<endl;
            cout<<temp<<endl;
            exit(0);
        }
        return;
    }
    vector<int> bp=config;
    if (temp.empty()||temp[temp.size()-1]!='A'){
        temp+="A";
        op_A();
        solve(x);
        config=bp;
        temp=temp.substr(0, temp.size()-1);
    }
    if (temp.size()<3||(temp[temp.size()-1]!='B'||temp[temp.size()-2]!='B'||temp[temp.size()-3]!='B')){
        temp+="B";
        op_B();
        solve(x);
        config=bp;
        temp=temp.substr(0, temp.size()-1);
    }
    if (temp.size()<3||(temp[temp.size()-1]!='C'||temp[temp.size()-2]!='C'||temp[temp.size()-3]!='C')){
        temp+="C";
        op_C();
        solve(x);
        config=bp;
        temp=temp.substr(0, temp.size()-1);
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main(){
    setIO("msquare");
    config={1, 2, 3, 4, 8, 7, 6, 5};
    for (int i=0;i<4;i++) cin>>target[i];
    for (int i=7;i>=4;i--) cin>>target[i];
    int moves=0;
    while (true){
        solve(moves++);
//        cout<<moves<<endl;
    }
}
#pragma clang diagnostic pop