#include <iostream>
#include <map>
#include <set>

using namespace std;

int low[200005], high[200005];

int main(){
    int n, m;
    string a, b;
    cin>>n>>m>>a>>b;
    int cur=0;
    for (int i=0;i<n;i++){
        if (a[i]==b[cur]){
            low[cur]=i;
            cur++;
            if (cur>=m) break;
        }
    }
    cur=m-1;
    for (int i=n-1;i>=0;i--){
        if (a[i]==b[cur]){
            high[cur--]=i;
            if (cur<0) break;
        }
    }
    int ans=0;
    for (int i=0;i<m-1;i++){
        ans=max(ans, high[i+1]-low[i]);
    }
    cout<<ans<<endl;
}