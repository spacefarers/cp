#include <iostream>
#include <algorithm>

using namespace std;

int tree[300000];
int k,m;
string decision;

void propagate(int t){
    if (t==1) return;
    int top,bot;
    if (t>=1<<k) bot=top=1;
    else{
        if (t%2){
            bot=tree[t];
            top=tree[t-1];
        } else{
            top=tree[t];
            bot=tree[t+1];
        }
    }
    if (decision[t/2]=='1')
        tree[t/2]=top;
    else if (decision[t/2]=='0')
        tree[t/2]=bot;
    else
        tree[t/2]=bot+top;
    propagate(t/2);
}

int main(){
    cin>>k>>decision>>m;
    reverse(decision.begin(),decision.end());
    decision="1"+decision;
    for (int i=0;i<(1<<(k));i++){
        tree[i]=1;
    }
    for (int i=(1<<(k+1))-1;i>=1<<(k);i--){
        propagate(i);
    }
    while (m--){
        int x;
        char b;
        cin>>x>>b;
        x=(1<<k)-x;
        decision[x]=b;
        propagate(x*2);
        cout<<tree[1]<<endl;
    }
}