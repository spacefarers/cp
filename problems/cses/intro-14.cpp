// Tower of Hanoi

#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string ans;
vector<int> f_ans, stacks[3];
int n;
map<int, int> where;

void solve(){
    if (ans.size()==n){
        return;
    }
    ans+='0';
    solve();
    ans=ans.substr(0, ans.size()-1);
    f_ans.push_back(ans.size());
    ans+='1';
    solve();
    ans=ans.substr(0, ans.size()-1);
}

int main(){
    cin>>n;
    cout<<pow(2, n)-1<<endl;
    solve();
    for (int i=0;i<n;i++) stacks[0].push_back(i);
    for (auto &i:f_ans){
        int t=where[i]+((n%2)?-1:1);
        t=(t%3+3)%3;
        while (!stacks[t].empty()&&stacks[t].back()>=i) {
            t+=((n%2)?-1:1);
            t=(t%3+3)%3;
        }
        cout<<where[i]+1<<" "<<t+1<<endl;
        stacks[where[i]].pop_back();
        stacks[t].push_back(i);
        where[i]=t;
    }
}