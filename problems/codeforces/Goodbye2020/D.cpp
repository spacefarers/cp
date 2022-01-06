#include <iostream>
#include <queue>

using namespace std;

int weight[100005], degree[100005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int ans=0;
        for (int i=0;i<n;i++){
            cin>>weight[i];
            ans+=weight[i];
        }
        for (int i=0;i<n;i++){
            int a, b;
            cin>>a>>b;
            degree[a]++;
            degree[b]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i=0;i<n;i++){
            if (degree[i]>1) q.push({weight[i], i});
        }
        for (int i=0;i<n-1;i++){
            cout<<ans<<" ";
            if (i!=n-2){
                while (degree[q.top().second]<=1) q.pop();
                auto u=q.top();
                ans+=u.first;
                degree[u.second]--;
            }
        }
        cout<<endl;
    }
}