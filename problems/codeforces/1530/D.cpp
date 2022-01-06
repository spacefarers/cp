// created on 2021/7/17 by spacefarers
// problem: D. Secret Santa

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_set>

#define ll long long
#define f first
#define s second

using namespace std;

int seen[200005];

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".txt").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    setIO("testcase");
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            seen[i]=-1;
        }
        vector<int> ss,faults;
        vector<int> output(n,-1);
        int alternative=-1;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            if (seen[a]!=-1||i+1==a){
                alternative=seen[a]+1;
                faults.push_back(i+1);
            } else seen[a]=i;
            output[i]=a;
        }
        for (int i=1;i<=n;i++){
            if (seen[i]==-1) ss.push_back(i);
        }
//        sort(ss.begin(),ss.end());
//        sort(faults.begin(),faults.end());
        if (faults.size()!=1){
            int cur1=0,cur2=0;
            while (cur1<ss.size()){
                if (faults[cur2++]==ss[cur1]){
                    swap(ss[cur1],ss[(cur1+1)%ss.size()]);
                }
                cur1++;
            }
            cur1=0,cur2=0;
            while (cur1<ss.size()){
                output[faults[cur2++]-1]=ss[cur1++];
            }
        } else {
            int f_ans=*faults.begin();
            if (f_ans==*ss.begin()){
                f_ans=alternative;
            }
            output[f_ans-1]=*ss.begin();
        }
        cout<<n-faults.size()<<endl;
        for (int i=0;i<n;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }
}