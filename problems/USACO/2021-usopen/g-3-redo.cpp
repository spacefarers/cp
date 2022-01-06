#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

#define pi pair<int,int>
#define f first
#define s second
#define ll long long

using namespace std;
#define PI 3.14159265
int N;
pi points[50];
ll MOD=1e9+7;


int cross(pi a,pi b,pi c){
    b.f-=a.f,b.s-=a.s;
    c.f-=a.f,c.s-=a.s;
    return b.f*c.s-b.s*c.f;
}

bool inTriangle(pi pt,pi a,pi b,pi c){
    double d1=cross(pt,a,b);
    double d2=cross(pt,b,c);
    double d3=cross(pt,c,a);
    bool has_neg=(d1<0)||(d2<0)||(d3<0);
    bool has_pos=(d1>0)||(d2>0)||(d3>0);
    return !(has_pos&&has_neg);
}


bool checkDir(pi pt,pi a,pi b,pi c){
    double d1=cross(a,b,pt);
    double d2=cross(c,b,pt);
    if (cross(c,b,pt)*cross(c,b,a)>0) return false;
    return d1*d2<0;
}

vector<ll> dp[105][105][105];

void add(vector<ll>&x,int k,ll b){
    while (x.size()<=k) x.push_back(0);
    x[k]+=b;
    x[k]%=MOD;
}

int main(){
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>points[i].f>>points[i].s;
    }
    vector<vector<int>> permutations;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            for (int k=j+1;k<N;k++){
                permutations.push_back({i,j,k});
            }
        }
    }
    sort(permutations.begin(),permutations.end(),[](vector<int>&a,vector<int>&b){
        return abs(cross(points[a[0]],points[a[1]],points[a[2]]))<abs(cross(points[b[0]],points[b[1]],points[b[2]]));
    });
//    auto stuff=permutations[0];
//    cout<<cross(points[stuff[0]],points[stuff[1]],points[stuff[2]])<<endl;
    ll ans=0;
    for (auto i:permutations){
        int tot_inside=0;
        vector<vector<int>> nex;
        for (int j=0;j<N;j++){
            if (inTriangle(points[j],points[i[0]],points[i[1]],points[i[2]])){
                tot_inside++;
            } else {
                for (int k=0;k<3;k++){
                    if (inTriangle(points[i[k]],points[i[(k+1)%3]],points[j],points[i[(k+2)%3]])){
                        nex.push_back({i[(k+1)%3],j,i[(k+2)%3]});
                        sort(nex.back().begin(),nex.back().end());
                        goto cont;
                    }
                }
                cont:;
            }
        }
        tot_inside-=3;
        dp[i[0]][i[1]][i[2]].resize(1+tot_inside);
        dp[i[0]][i[1]][i[2]][0]=1;
        for (int j=0;j<=tot_inside;j++){
            ll last=dp[i[0]][i[1]][i[2]][j];
            if (j<tot_inside){
                add(dp[i[0]][i[1]][i[2]],j+1,(tot_inside-j)*last);
            }
            for (auto k:nex){
                add(dp[k[0]][k[1]][k[2]],j+1,last);
            }
        }
        if (tot_inside==N-3){
            ans+=dp[i[0]][i[1]][i[2]][tot_inside];
            ans%=MOD;
        }
    }
    cout<<(6*ans)%MOD<<endl;
}