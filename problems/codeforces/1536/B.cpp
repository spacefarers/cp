#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string,bool> mp;

int main(){
    int t;
    cin>>t;
    while (t--){
        mp.clear();
        int n;
        string a;
        cin>>n>>a;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=n-i;j++){
                mp[a.substr(j,i)]=true;
            }
        }
        vector<string> tried,new_tried;
        tried.emplace_back("");
        while (true){
            for (const string &j:tried){
                for (char i='a';i<='z';i++){
                    if (mp[j+i]){
                        new_tried.push_back(j+i);
                    } else {
                        cout<<j+i<<endl;
                        goto cont;
                    }
                }
            }
            tried=new_tried;
            new_tried.clear();
        }
        cont:;
    }
}