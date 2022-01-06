// created on 2021/6/28 by spacefarers
// problem: C. Epidemic in Monstropolis

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

vector<int> c;
int base;

int main(){
    int n;
    cin>>n;
    vector<int> initial,end;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        initial.push_back(a);
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        end.push_back(a);
    }
    reverse(end.begin(),end.end());
    int sum=0;
    for (int i=0;i<n;i++){
        c.push_back(initial[i]);
        sum+=initial[i];
        if (end.empty()||sum>end.back()) goto cont;
        else if (sum==end.back()){
            end.pop_back();
            sum=0;
            ok=false;
            int max_val=-1e9;
            for (auto j:c){
                if (j>max_val) max_val=j;
            }
            bool ok=false;
            for (int j=0;j<c.size();j++){
                if (c[j]==max_val){
                    int left=j-1,right=j+1;
                    if (left>=0&&c[left]<max_val)
                }
            }
            if (!ok) goto cont;
            c.clear();
            base=i;
        }
    }
    cout<<"YES"<<endl;
    for (auto i:ans){
        cout<<i.f+1<<" "<<i.s<<endl;
    }
    exit(0);
    cont:;
    cout<<"NO"<<endl;
}