#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int>> cows;
int counts=0;
int n;

bool validate(int x){
    int c_count=0;
    queue<pair<int,int>> q;
    map<int,int> hit;
    for (auto i:cows){
        while (!q.empty()&&i.first-x>q.front().first){
            if (--hit[q.front().second]==0) c_count--;
            q.pop();
        }
        q.push(i);
        if (hit[i.second]++==0) c_count++;
        if (c_count==counts) return true;
    }
    return false;
}

int main(){
    cin>>n;
    map<int,int> mp;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        cout<<mp[b]<<endl;
        if (!mp[b]) mp[b]=counts++;
        cows.emplace_back(a,mp[b]);
    }
    sort(cows.begin(), cows.end());
    int z=-1;
    for (int i=1e9;i>=1;i/=2){
        while (!validate(z+i)) z+=i;
    }
    cout<<z+1<<endl;
}