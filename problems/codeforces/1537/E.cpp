// created on 6/18/21 by spacefarers
// problem: E. Erase and Extend

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n,k;
    string x;
    cin>>n>>k>>x;
    string first,ans;
    first+=x[0];
    int i;
    for (i=1;i<n;i++){
        if (x[i]<x[0]) first+=x[i];
        else break;
    }
    ans+=first;
    string tmp;
    while (i<n){
        tmp+=x[i++];
        for (;i<n;i++){
            if (x[i]<tmp[0]) tmp+=x[i];
            else break;
        }
        bool use=true;
        int common_size=(int)min(tmp.size(),ans.size());
        if (tmp.substr(0,common_size)>ans.substr(0,common_size)) use=false;
        else if (tmp.substr(0,common_size)==ans.substr(0,common_size)&&tmp.size()<ans.size()){
            goto cont;
        }
        if (use){
            ans+=tmp;
            tmp="";
        } else break;
        cont:;
    }
    while (ans.size()<k) ans+=ans;
    ans=ans.substr(0,k);
    cout<<ans<<endl;
}