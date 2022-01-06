#include <iostream>
#include <cstring>

using namespace std;

string patterns[100005];

bool match(string &a, int b){
    for (int i=0;i<a.size();i++){
        if (patterns[b][i]!='_'&&patterns[b][i]!=a[i]) return false;
    }
    return true;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        cin>>patterns[i];
    }

}