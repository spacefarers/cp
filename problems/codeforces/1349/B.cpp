// created on 2021/7/2 by spacefarers
// problem: B. Orac and Medians

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

#define MAX 100005

int nums[MAX];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        int a;
        bool impos=true;
        for (int i=1;i<=n;i++){
            cin>>a;
            if (a<k) nums[i]=1;
            else if (a==k){
                nums[i]=2;
                impos=false;
            }
            else nums[i]=3;
        }
        if (impos){
            cout<<"NO"<<endl;
            continue;
        }
        bool ok=false;
        for (int i=1;i<=n;i++){
            vector<int> num(3);
            if (i!=1) num[0]=nums[i-1];
            num[1]=nums[i];
            if (i!=n) num[2]=nums[i+1];
            sort(num.begin(),num.end());
            if (num[1]==2||num[1]==3) ok=true;
        }
        if (ok||n==1&&a==k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}