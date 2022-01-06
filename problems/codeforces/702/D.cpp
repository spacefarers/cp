#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> nums;
int ans[105];

#define f first
#define s second

void solve(int left, int right, int dep){
    if (left>right) return;
    pair<int, int> max_num;
    for (int i=left;i<=right;i++){
        if (nums[i]>max_num.f) max_num={nums[i], i};
    }
    ans[max_num.s]=dep;
    solve(left, max_num.s-1, dep+1);
    solve(max_num.s+1, right, dep+1);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(ans, 0, sizeof ans);
        int n;
        cin>>n;
        nums.clear();
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.push_back(a);
        }
        solve(0, n-1, 0);
        for (int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}