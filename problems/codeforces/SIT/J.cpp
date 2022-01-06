#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;
    while (t--){
        int n, k;
        cin>>n>>k;
        vector<ll> problems;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i=0;i<n;i++){
            ll a;
            cin>>a;
            problems.push_back(a);
        }
        for (int i=0;i<k;i++){
            q.push(0);
        }
        sort(problems.begin(), problems.end(), greater<ll>());
        for (auto &i:problems){
            ll u=q.top();
            q.pop();
            u+=i;
            q.push(u);
        }
        for (int i=0;i<k-1;i++) q.pop();
        cout<<q.top()<<endl;
    }
}