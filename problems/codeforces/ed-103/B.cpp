#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> nums;
int p, k;

bool validate(long long x){
    long long sums=nums.front()+x;
    for (int i=1;i<nums.size();++i){
        if (nums[i]*100>k*sums) return false;
        sums+=nums[i];
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        nums.clear();
        cin>>p>>k;
        for (int i=0;i<p;++i){
            long long a;
            cin>>a;
            nums.push_back(a);
        }
        long long z=-1;
        for (long long i=1e13;i>=1;i/=2){
            while (!validate(z+i)) {
                z+=i;
            }
        }
        cout<<z+1<<endl;
    }
}