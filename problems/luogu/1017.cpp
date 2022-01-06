#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int n, r;
map<int, string> nums;

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>r;
    string final;
    nums[10] = "A";
    nums[11] = "B";
    nums[12] = "C";
    nums[13] = "D";
    nums[14] = "E";
    nums[15] = "F";
    nums[16] = "G";
    nums[17] = "H";
    nums[18] = "I";
    nums[19] = "J";
    while (abs(n)>0){
        int rem = (r+(n%r))%r;
        cout<<rem<<endl;
        if (rem<10){
            final = to_string(rem)+final;
        } else {
            final = nums[rem]+final;
        }
        n/=r;qq

    }
    cout<<final<<endl;
}