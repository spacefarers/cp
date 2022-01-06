// created on 2021/7/11 by spacefarers
// problem: 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int s1=0,s2=0;
        vector<int> arr1,arr2;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            s1+=a;
            arr1.push_back(a);
        }
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            s2+=a;
            arr2.push_back(a);
        }
        if (s1!=s2) cout<<-1<<endl;
        else {
            vector<int> diff(n);
            for (int i=0;i<n;i++){
                diff[i]=arr1[i]-arr2[i];
            }
            int neg_pos=0;
            vector<pair<int,int>> ans;
            for (int i=0;i<n;i++){
                while (neg_pos<n&&diff[neg_pos]>=0) neg_pos++;
                if (diff[i]>0){
                    ans.emplace_back(i,neg_pos);
                    diff[i]--,diff[neg_pos]++;
                    if (diff[i]>0) i--;
                }
            }
            cout<<ans.size()<<endl;
            for (auto i:ans){
                cout<<i.f+1<<" "<<i.s+1<<endl;
            }
        }
    }
}