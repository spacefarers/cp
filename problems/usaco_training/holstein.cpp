/*
ID: michael419
LANG: C++
TASK: holstein
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int feeds[15][25], v, g;
vector<vector<bool>> possibilities;
vector<bool> c;

void generate_bits(){
    if (c.size()==g){
        possibilities.push_back(c);
        return;
    }
    c.push_back(false);
    generate_bits();
    c.pop_back();
    c.push_back(true);
    generate_bits();
    c.pop_back();
}

int main(){
    setIO("holstein");
    cin>>v;
    vector<int> nums;
    for (int i=0;i<v;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    cin>>g;
    for (int i=0;i<g;i++){
        for (int j=0;j<v;j++){
            cin>>feeds[i][j];
        }
    }
    vector<int> ans;
    generate_bits();
    for (auto &i:possibilities){
        auto cp=nums;
        for (int j=0;j<g;j++){
            if (i[j]){
                for (int k=0;k<v;k++){
                    cp[k]-=feeds[j][k];
                }
            }
        }
        for (int j=0;j<v;j++){
            if (cp[j]>0) goto cont;
        }
        if (false){
            cont:;
            continue;
        }
        vector<int> c_ans;
        for (int j=0;j<g;j++){
            if (i[j]) c_ans.push_back(j+1);
        }
        if (ans.empty()) ans=c_ans;
        if (ans.size()>c_ans.size()||(ans.size()==c_ans.size()&&c_ans<ans)) ans=c_ans;
    }
    cout<<ans.size();
    for (auto &i:ans){
        cout<<" "<<i;
    }
    cout<<endl;
}