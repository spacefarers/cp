#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> copies;

vector<pair<int, int>> validate(){
    for (int i=1;i<n;i++){
        vector<pair<int, int>> misplaces;
        for (int j=0;j<m;j++){
            if (copies[i][j]!=copies[0][j]) misplaces.emplace_back(j, copies[i][j]);
        }
        if (misplaces.size()>2) return misplaces;
    }
    return vector<pair<int, int>>();
}

void output_result(){
    cout<<"YES"<<endl;
    for (auto &i:copies[0]){
        cout<<i<<" ";
    }
    exit(0);
}

void solve(){
    auto results=validate();
    if (results.empty()){
        output_result();
    } else if (results.size()>4){
        cout<<"NO"<<endl;
        exit(0);
    }
    if (results.size()==3){
        auto bp=copies;
        for (auto &i:results){
            copies[0][i.first]=i.second;
            auto result2=validate();
            if (result2.empty()) output_result();
            if (result2.size()==3){
                auto bp2=copies;
                for (auto &j:result2){
                    copies[0][j.first]=j.second;
                    auto result3=validate();
                    if (result3.empty()) output_result();
                    copies=bp2;
                }
            }
            copies=bp;
        }
    } else {
        auto bp=copies;
        for (auto &i:results){
            for (auto &j:results){
                if (i==j) continue;
                copies[0][i.first]=i.second;
                copies[0][j.first]=j.second;
                auto result2=validate();
                if (result2.empty()) output_result();
                copies=bp;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++){
        vector<int> temp;
        for (int j=0;j<m;j++){
            int a;
            cin>>a;
            temp.push_back(a);
        }
        copies.push_back(temp);
    }
    solve();
}