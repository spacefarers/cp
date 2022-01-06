#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

long long best_ans=0, sum_all=0;

vector<long long> apples;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        long long a;
        cin>>a;
        apples.push_back(a);
        sum_all+=a;
    }
    sort(apples.begin(), apples.end(), greater<int>());
    for (int i=0;i<1<<n;i++) {
        ll c_s=0;
        for (int j=0;j<n;j++){
            if (i>>j&1)
                c_s+=apples[j];
        }
        if (2*c_s<=sum_all){
            best_ans=max(best_ans, c_s);
        }
    }
    cout<<sum_all-2*best_ans<<endl;
}