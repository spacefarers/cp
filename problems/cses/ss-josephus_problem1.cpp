#include <iostream>
#include <vector>

using namespace std;

int father[200005];

int find(int x){
    if (father[x]!=x) father[x]=find(father[x]);
    return father[x];
}

int main(){
    int n;
    cin>>n;
    int pos=0;
    vector<int> ans;
    for (int i=n-1;i>=1;i--){
        pos+=2;
        pos%=i;
        father[pos]=find((pos+1)%i)c;
    }
}