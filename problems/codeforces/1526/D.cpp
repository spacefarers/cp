// created on 2021/6/16 by spacefarers
// problem: D. Kill Anton

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define ll long long
#define f first
#define s second

using namespace std;

int tree[100005];
int n;

void add(int k,int x){
    while (k<=n){
        tree[k]+=x;
        k+=k&-k;
    }
}
ll get_sum(int k){
    int ans=0;
    while (k>=1){
        ans+=tree[k];
        k-=k&-k;
    }
    return ans;
}

vector<int> pos[26];

int main(){
    int t;
    cin>>t;
    while (t--){
        string x;
        cin>>x;
        for (int i=0;i<26;i++){
            pos[i].clear();
        }
        n=(int)x.size();
        set<int> tmp_order; // core optimization, speeds up by 24x when facing 1e5 * 1.
        for (int i=0;i<x.size();i++){
            pos[x[i]-'A'].push_back(i+1);
            tmp_order.insert(x[i]-'A');
        }
        vector<int> order;
        order.reserve(tmp_order.size());
        for (auto i:tmp_order){
            order.push_back(i);
        }
        string ans;
        ll max_ans=-1;
        do {
            memset(tree,0,sizeof tree);
            ll c_ans=0;
            for (auto m:order){
                for (auto i:pos[m]){
                    c_ans+=i-get_sum(i)-1;
                    add(i,1);
                }
            }
            if (max_ans<c_ans){
                ans="";
                for (auto m:order){
                    ans+=string((int)pos[m].size(),char('A'+m));
                }
                max_ans=c_ans;
            }
        } while (next_permutation(order.begin(),order.end()));
        cout<<ans<<endl;
    }
}