// created on 2021/6/27 by spacefarers
// problem: A - Remove Substrings

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n;
    string x;
    cin>>n>>x;
    if (x.front()==x.back()){
        for (int i=0;i<n-1;i++){
            if (x[i]!=x.front()&&x[i+1]!=x.front()){
                cout<<2<<endl;
                goto cont;
            }
        }
        cout<<-1<<endl;
        cont:;
    } else {
        cout<<1<<endl;
    }
}