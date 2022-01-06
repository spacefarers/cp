#include <iostream>
#include <vector>

using namespace std;

bool in_middle(int a, int b, int c){
    return a>=b&&a<=c;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> friends;
    vector<int> events;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        events.push_back(a+b);
        events.push_back(a);
        friends.emplace_back(a, a+b);
    }
    int ans=0;
    for (auto &i:events){
        int c=0;
        for (auto &j:friends){
            if (in_middle(j.first, i, i+m)||in_middle(j.second, i, i+m)||(j.first<=i&&j.second>=i+m)) c++;
        }
        ans=max(ans, c);
    }
    cout<<ans<<endl;
}