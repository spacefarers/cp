// created on 2021/7/11 by spacefarers
// problem: C. AquaMoon and Strange Sort

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
        vector<int> arr1,arr2;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            if (i%2) arr1.push_back(a);
            else arr2.push_back(a);
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int c=0;
        for (int i=0;i<n;i++){
            if (i%2){
                c=max(c,arr1[i/2]);
                if (c>arr1[i/2]) goto fail;
            } else {
                c=max(c,arr2[i/2]);
                if (c>arr2[i/2]) goto fail;
            }
        }
        cout<<"YES"<<endl;
        goto cont;
        fail:;
        cout<<"NO"<<endl;
        cont:;
    }
}