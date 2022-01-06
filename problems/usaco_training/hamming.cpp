/*
ID: michael419
LANG: C++
TASK: hamming
*/

#include <iostream>
#include <vector>

using namespace std;

#define f first
#define s second

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int dist[1000][1000];
int n, b, d, max_size;
vector<int> ans;

void solve(){
    if (ans.size()==n){
        int cur=0;
        for (int i=0;i<n/10;i++){
            cout<<ans[cur++];
            for (int j=0;j<9;j++){
                cout<<" "<<ans[cur++];
            }
            cout<<endl;
        }
        if (cur<ans.size()){
            cout<<ans[cur++];
            while (cur<ans.size()){
                cout<<" "<<ans[cur++];
            }
            cout<<endl;
        }
        exit(0);
    }
    int a=-1;
    if (!ans.empty()) a=ans.back();
    for (int i=a+1;i<max_size;i++){
        for (auto &j:ans){
            if (dist[j][i]<d) goto cont;
        }
        ans.push_back(i);
        solve();
        ans.pop_back();
        cont:;
    }
}

int main(){
    setIO("hamming");
    cin>>n>>b>>d;
    max_size=1<<(b+1);
    for (int i=0;i<max_size;i++){
        for (int j=0;j<max_size;j++){
            for (int k=0;k<b;k++){
                if (((1<<k)&i)!=((1<<k)&j)) dist[i][j]++;
            }
        }
    }
    solve();
}