#include <iostream>
#include <deque>
#include <vector>

using namespace std;


int main(){
    int n, k;
    cin>>n>>k;
    deque<pair<long long,long long>> min_q,max_q;
    vector<long long> ans;
    for (int i=0;i<n;i++){
        while (!min_q.empty()&&min_q.front().first<=i-k) min_q.pop_front();
        while (!max_q.empty()&&max_q.front().first<=i-k) max_q.pop_front();
        long long a;
        cin>>a;
        while (!min_q.empty()&&min_q.back().second>a) min_q.pop_back();
        while (!max_q.empty()&&max_q.back().second<a) max_q.pop_back();
        min_q.emplace_back(i,a);
        max_q.emplace_back(i,a);
        if (i<k-1) continue;
        cout<<min_q.front().second<<" ";
        ans.push_back(max_q.front().second);
    }
    cout<<endl;
    for (auto i:ans){
        cout<<i<<" ";
    }
}