#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> nums;
        pair<int,int> min_num={1e9,-1},max_num={0,-1};
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.push_back(a);
            if (a<min_num.first) min_num={a,i};
            if (a>max_num.first) max_num={a,i};
        }
        int h=min_num.second+1;
        int i=max_num.second+1;
        if (h>i) swap(h,i);
        cout<<min(min(i,n-h+1),h+n-i+1)<<endl;
    }
}