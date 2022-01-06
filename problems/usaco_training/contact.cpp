/*
ID: michael419
LANG: C++
TASK: contact
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
    setIO("contact");
    int A, B, N;
    string seq, x;
    cin>>A>>B>>N;
    while (cin>>x){
        seq+=x;
    }
    map<string, int> mp;
    for (int i=A;i<=B;i++){
        for (int j=0;j<=(int)seq.size()-i;j++){
            string sub_seq=seq.substr(j, i);
            mp[sub_seq]++;
        }
    }
    vector<pair<int, string>> ans;
    ans.reserve(mp.size());
    for (auto &i:mp){
        ans.emplace_back(i.s, i.f);
    }
    sort(ans.begin(), ans.end(), greater<pair<int, string>>());
    map<int, vector<string>, greater<int>> final_ans;
    for (auto &an:ans){
        final_ans[an.f].push_back(an.s);
    }
    int c=0;
    for (auto &i:final_ans){
        if (c++>=N) break;
        vector<string> temp=i.s;
        sort(temp.begin(), temp.end(), [](string &a, string &b){
            if (a.size()==b.size()) return a<b;
            return a.size()<b.size();
        });
        cout<<i.f<<endl;
        int cur=0;
        while (cur<temp.size()){
            string output;
            for (int j=0;j<6;j++){
                if (cur>=temp.size()) break;
                output+=temp[cur++]+" ";
            }
            output=output.substr(0, output.size()-1);
            cout<<output<<endl;
        }
    }
}