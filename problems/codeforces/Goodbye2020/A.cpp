#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> trees(n);
        for (int i=0;i<n;i++){
            cin>>trees[i];
        }
        set<int> used;
        for (auto &i:trees){
            for (auto &j:trees){
                if (i==j) continue;
                used.insert(abs(i-j));
            }
        }
        cout<<used.size()<<endl;
    }
}