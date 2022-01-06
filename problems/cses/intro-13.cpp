// Gray Code

#include <iostream>
#include <vector>

using namespace std;

string ans;
vector<string> f_ans;
int n;

void solve(){
    if (ans.size()==n){
        f_ans.push_back(ans);
        return;
    }
    ans+='0';
    solve();
    ans=ans.substr(0, ans.size()-1);
    ans+='1';
    solve();
    ans=ans.substr(0, ans.size()-1);
}

int main(){
    cin>>n;
    solve();
    for (auto &i:f_ans){
        string out;
        out+=i[0];
        for (int j=0;j<n-1;j++){
            out+=(i[j]==i[j+1])?'0':'1';
        }
        cout<<out<<endl;
    }
}