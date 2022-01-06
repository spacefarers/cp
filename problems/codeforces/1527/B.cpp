// created on 2021/6/14 by spacefarers
// problem: B. Palindrome Game

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

string x;
int next_palin(){
    string f_half=x.substr(0,x.size()/2);
    string other_half=x.substr(x.size()-x.size()/2,x.size()/2);
    reverse(other_half.begin(),other_half.end());
    if (f_half==other_half) return 0;
    int ans=0;
    for (int i=0;i<x.size()/2;i++){
        if (f_half[i]!=other_half[i]){
            ans++;
            x[i]='1';
            x[x.size()-i-1]='1';
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n>>x;
        int steps_from_palin=next_palin();
        int moves=0;
        for (auto i:x){
            if (i=='0') moves++;
        }
        if (steps_from_palin==0){
            if (moves%2&&moves>=3) cout<<"ALICE"<<endl;
            else cout<<"BOB"<<endl;
        } else {
            if (steps_from_palin>1) cout<<"ALICE"<<endl;
            else {
                if (moves==1) cout<<"DRAW"<<endl;
                else cout<<"ALICE"<<endl;
            }
        }
    }
}