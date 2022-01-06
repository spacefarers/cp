/*
ID: michael419
LANG: C++
TASK: sort3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second

int counts[4][4];

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);

int main(){
    setIO("sort3");
    int n;
    cin>>n;
    vector<int> orig, correct;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        orig.push_back(a);
        correct.push_back(a);
    }
    sort(correct.begin(), correct.end());
    int ans=0, f_ans=0;
    for (int i=0;i<n;i++){
        if (orig[i]!=correct[i]){
            int a=orig[i], b=correct[i];
            if (counts[b][a]) {counts[b][a]--;ans--;f_ans++;}
            else {counts[a][b]++;ans++;}
        }
    }
    cout<<f_ans+ans/3*2<<endl;
}