// created on 2021/6/29 by spacefarers
// problem: E. Plan of Lectures

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

#define ll long long
#define f first
#define s second

using namespace std;

int deg[300005];
vector<int> paths[300005],follow[300005];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        if (a) deg[i]++;
        paths[a].push_back(i);
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        follow[a].push_back(b);
    }
    stack<int> st;
    st.push(0);
    while (!st.empty()){
        if ()
    }
}