// created on 2021/6/15 by spacefarers
// problem: C. Potions

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

// Priority Queue implementation O(nlogn) easy code
int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<>> q;
    ll health=0,ans=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        health+=a;
        q.push(a);
        ans++;
        while (health<0){
            int x=q.top();
            q.pop();
            health-=x;
            ans--;
        }
    }
    cout<<ans<<endl;
}

// Segment Tree Approach, passes with O(nlogn)
//ll input[200005],tree[800005],lazy[800005];
//int n;
//
//void build_tree(int s=1,int t=n,int p=1){
//    if (s==t){
//        tree[p]=input[s];
//        return;
//    }
//    int m=(t+s)/2;
//    build_tree(s,m,p*2);
//    build_tree(m+1,t,p*2+1);
//    tree[p]=min(tree[p*2],tree[p*2+1]);
//}
//
//void update_tree(int l,int r,ll c,int s=1,int t=n,int p=1){
//    if (l<=s&&t<=r){
//        tree[p]+=c;
//        lazy[p]+=c;
//        return;
//    }
//    int m=(t+s)/2;
//    if (lazy[p]&&s!=t){
//        tree[p*2]+=lazy[p],tree[p*2+1]+=lazy[p];
//        lazy[p*2]+=lazy[p];
//        lazy[p*2+1]+=lazy[p];
//        lazy[p]=0;
//    }
//    if (l<=m) update_tree(l,r,c,s,m,p*2);
//    if (r>m) update_tree(l,r,c,m+1,t,p*2+1);
//    tree[p]=min(tree[p*2],tree[p*2+1]);
//}
//
//ll get_min(int l,int r,int s=1,int t=n,int p=1){
//    if (l<=s&&t<=r) return tree[p];
//    int m=(t+s)/2;
//    ll min_num=1e15;
//    if (lazy[p]){
//        tree[p*2]+=lazy[p],tree[p*2+1]+=lazy[p];
//        lazy[p*2]+=lazy[p];
//        lazy[p*2+1]+=lazy[p];
//        lazy[p]=0;
//    }
//    if (l<=m) min_num=get_min(l,r,s,m,p*2);
//    if (r>m) min_num=min(min_num,get_min(l,r,m+1,t,p*2+1));
//    return min_num;
//}
//
//int main(){
//    cin>>n;
//    vector<pair<int,int>> nums;
//    int ans=0;
//    for (int i=1;i<=n;i++){
//        int a;
//        cin>>a;
//        if (a<0) nums.emplace_back(-a,i);
//        else input[i]=a,ans++;
//    }
//    for (int i=2;i<=n;i++){
//        input[i]+=input[i-1];
//    }
//    build_tree();
//    sort(nums.begin(),nums.end());
//    for (auto i:nums){
//        if (get_min(i.second,n)>=i.first){
//            ans++;
//            update_tree(i.second,n,-i.first);
//        }
//    }
//    cout<<ans<<endl;
//}

// Old Version naive DP O(n^2)
//ll n,dp[2005][2005],potions[2005],MIN=-1e15;
//
//int main(){
//    cin>>n;
//    for (int i=0;i<n;i++){
//        cin>>potions[i];
//    }
//    for (int i=0;i<=n;i++){
//        for (int j=0;j<=n;j++){
//            dp[i][j]=MIN;
//        }
//    }
//    for (int i=0;i<n;i++){
//        dp[i][0]=0;
//    }
//    if (potions[0]>=0) dp[0][1]=potions[0];
//    for (int i=1;i<n;i++){
//        for (int j=1;j<=i+1;j++){
//            dp[i][j]=max(dp[i-1][j-1]+potions[i],dp[i-1][j]);
//            if (dp[i][j]<0) dp[i][j]=MIN;
//        }
//    }
//    for (int i=1;i<=n;i++){
//        if (dp[n-1][i]<0){
//            cout<<i-1<<endl;
//            exit(0);
//        }
//    }
//    cout<<n<<endl;
//}