#include <iostream>

using namespace std;

int ans[100005];

int find(int x){
    if (ans[x]) return ans[x];
    cout<<"? "<<x<<endl;
    cout.flush();
    int ans1;
    cin>>ans1;
    ans[x]=ans1;
    return ans1;
}

int main(){
    int n;
    cin>>n;
    int left=1, right=n;
    while (left<right){
        int k=(left+right)/2;
        int u=find(k);
        int u2=find(k+1);
        if (u2>u) right=k;
        else left=k+1;
    }
    cout<<"! "<<left<<endl;
}