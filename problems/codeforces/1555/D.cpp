// created on 2021/7/30 by spacefarers
// problem: D. Say No to Palindromes

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int costs[6][200005];

int main(){
    int n,m;
    string x;
    cin>>n>>m>>x;
    vector<char> patterns={'a','b','c'};
    int count=0;
    do {
        int cIndex=0;
        for (int i=1;i<=n;i++){
            costs[count][i]+=costs[count][i-1];
            if (x[i-1]!=patterns[cIndex]) costs[count][i]++;
            cIndex++;
            cIndex%=3;
        }
        count++;
    } while (next_permutation(patterns.begin(),patterns.end()));
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int ans=1e9;
        for (auto j:costs){
            ans=min(ans,j[b]-j[a-1]);
        }
        cout<<ans<<endl;
    }
}