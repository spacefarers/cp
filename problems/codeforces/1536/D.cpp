// created on 2021/6/17 by spacefarers
// problem: D. Omkar and Medians

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

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
        set<int> st;
        int a;
        cin>>a;
        st.insert(a);
        int median=a;
        vector<int> nums;
        for (int i=1;i<n;i++){
            cin>>a;
            nums.push_back(a);
        }
        for (int i=0;i<n-1;i++){
            a=nums[i];
            st.insert(a);
            bool ok=false;
            if (st.find(median)==st.find(a)) ok=true;
            if (st.find(median)!=st.begin()){
                if (st.find(a)==--st.find(median)) ok=true;
            }
            if (st.find(median)!=st.end()){
                if (st.find(a)==++st.find(median)) ok=true;
            }
            median=a;
            if (!ok){
                cout<<"NO"<<endl;
                goto cont;
            }
        }
        cout<<"YES"<<endl;
        cont:;
    }
}