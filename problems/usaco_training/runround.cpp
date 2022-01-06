/*
ID: michael419
LANG: C++
TASK: runround
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define f first
#define s second

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vector<long long> nums;
string c_num;
int c;
bool used[10], vis[10];

void solve(){
    if (c_num.size()==c){
        nums.push_back(stoll(c_num));
        return;
    }
    for (int i=1;i<=9;i++){
        if (!used[i]){
            used[i]=true;
            c_num+=to_string(i);
            solve();
            used[i]=false;
            c_num=c_num.substr(0, c_num.size()-1);
        }
    }
}

int main(){
    setIO("runround");
    long long n;
    cin>>n;
    string a=to_string(n);
    for (int i=a.size();i<10;i++){
        c=i;
        solve();
        for (auto &i:nums){
            if (i<=n) continue;
            memset(vis, false, sizeof vis);
            string ss=to_string(i);
            int cur=0;
            for (int j=0;j<ss.size();j++){
                int target=(ss[cur]-'0'+cur)%(int)ss.size();
                if (vis[target]) goto cont;
                vis[target]=true;
                cur=target;
            }
            cout<<i<<endl;
            exit(0);
            cont:;
        }
        nums.clear();
    }
}