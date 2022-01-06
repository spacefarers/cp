// created on 2021/7/1 by spacefarers
// problem: C. Busy Robot

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<pair<ll,ll>> cmds;
        for (int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            cmds.emplace_back(a,b);
        }
        cmds.emplace_back(1e14,0);
        ll from=0,ans=0,last_cmd=0;
        pair<ll,ll> pos={0,0};
        for (int i=0;i<n;i++){
            auto cmd=cmds[i];
            if (pos.f>cmd.f){
                // cmd ignored
                // check range
                if (pos.s<from&&cmd.s>from||pos.s>from&&cmd.s<from) continue;
                ll dist=abs(from-cmd.s),min_time=cmd.f-last_cmd,max_time=min(cmds[i+1].f,pos.f)-last_cmd;
                if (dist>=min_time&&dist<=max_time) ans++;
            } else {
                // exec cmd
                from=pos.s;
                pos=cmd;
                pos.f+=abs(from-pos.s);
                last_cmd=cmd.f;
                if (cmds[i+1].f>=pos.f) ans++;
            }
        }
        cout<<ans<<endl;
    }
}