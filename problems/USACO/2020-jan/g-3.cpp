// created on 2021/6/23 by spacefarers
// problem: Problem 3. Springboards

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

int dp[100005]; //最短走到i的距离
vector<pair<pair<int,int>,pair<int,bool>>> sb;
map<int,int> saved;

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    setIO("boards");
    int n,p;
    cin>>n>>p;
    for (int i=0;i<p;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        sb.push_back({{a,b},{i,true}});
        sb.push_back({{c,d},{i,false}});
    }
    sort(sb.begin(),sb.end());
    saved[0]=0;
    for (auto i:sb){
        if (i.s.s){
            dp[i.s.f]=i.f.f+i.f.s-prev(saved.upper_bound(i.f.s))->s;
        } else {
            int dist_saved=i.f.f+i.f.s-dp[i.s.f];
            auto it=prev(saved.upper_bound(i.f.s));
            if (it->s>=dist_saved) continue;
            it++;
            while (it!=saved.end()&&it->s<=dist_saved) saved.erase(it++);
            saved[i.f.s]=dist_saved;
        }
    }
    cout<<2*n-prev(saved.end())->s<<endl;
}