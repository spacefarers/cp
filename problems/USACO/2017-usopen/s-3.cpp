#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
struct PCL { int i1,j1,i2,j2; };
vector<PCL> V;


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

string board[25];
int x_1, x_2, y_1, y_2;
bool visited[25][25], beenthere[25][25];
vector<pair<pi, pi>> pcls;

void visit(int i, int j, int c, int i1, int j1, int i2, int j2)
{
    beenthere[i][j] = true;
    if (i > i1 && board[i-1][j]-'A'==c && !beenthere[i-1][j])
        visit(i-1,j,c,i1,j1,i2,j2);
    if (i < i2 && board[i+1][j]-'A'==c && !beenthere[i+1][j])
        visit(i+1,j,c,i1,j1,i2,j2);
    if (j > j1 && board[i][j-1]-'A'==c && !beenthere[i][j-1])
        visit(i,j-1,c,i1,j1,i2,j2);
    if (j < j2 && board[i][j+1]-'A'==c && !beenthere[i][j+1])
        visit(i,j+1,c,i1,j1,i2,j2);
}

bool is_PCL(int i1, int j1, int i2, int j2)
{
    int num_colors = 0;
    int color_count[26] = {0};
    for (int i=i1; i<=i2; i++)
        for (int j=j1; j<=j2; j++)
            beenthere[i][j] = false;
    for (int i=i1; i<=i2; i++)
        for (int j=j1; j<=j2; j++)
            if (!beenthere[i][j]) {
                int c = board[i][j] - 'A';
                if (color_count[c] == 0) num_colors++;
                color_count[c]++;
                visit(i,j,c,i1,j1,i2,j2);
            }
    if (num_colors != 2) return false;
    bool found_one=false, found_many=false;
    for (int i=0; i<26; i++) {
        if (color_count[i] == 1) found_one = true;
        if (color_count[i] > 1) found_many = true;
    }
    return found_one && found_many;
}

bool PCL_in_PCL(int x, int y)
{
    return V[x].i1 >= V[y].i1
           && V[x].i2 <= V[y].i2
           && V[x].j1 >= V[y].j1
           && V[x].j2 <= V[y].j2;
}

bool PCL_maximal(int x)
{
    for (int i=0; i<V.size(); i++)
        if (i!=x && PCL_in_PCL(x,i)) return false;
    return true;
}

void dfs(int x, int y, char color){
    if (visited[x][y]||x<x_1||x>x_2||y<y_1||y>y_2||color!=board[x][y]) return;
    visited[x][y]=true;
//    cout<<x<<" "<<y<<endl;
    dfs(x-1, y, color);
    dfs(x+1, y, color);
    dfs(x, y-1, color);
    dfs(x, y+1, color);
}

int main() {
    setIO("where");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>board[i];
    }
    int ans=0;
//    for (int i=0;i<n;i++){
//        for (int j=i;j<n;j++){
//            for (int a=0;a<n;a++){
//                for (int b=a;b<n;b++){
////                    x_1=i; x_2=j; y_1=a; y_2=b;
////                    char c1, c3;
////                    c1=0;c3=0;
////                    int c2, c4;
////                    bool ok=true;
////                    memset(visited, false, sizeof(visited));
////                    for (int c=x_1;c<=x_2;c++){
////                        for (int d=y_1;d<=y_2;d++) {
////                            if (!visited[c][d]) {
////                                if (c1==0) {c1=board[c][d];c2=1;}
////                                else if (c1==board[c][d]) c2++;
////                                else if (c3==0) {c3=board[c][d];c4=1;}
////                                else if (c3==board[c][d]) c4++;
////                                else ok=false;
////                                dfs(c, d, board[c][d]);
////                            }
////                        }
////                    }
////                    if (c1==0||c3==0) continue;
////                    if (ok&&((c2==1&&c4>=2)||(c2>=2&&c4==1))){
//////                        cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
////                        ans++;
////                        pcls.pb({{i, j}, {a, b}});
////                    }
//                    if (is_PCL(i, j, a, b)){
//                        pcls.pb({{i, j}, {a, b}});
////                        ans++;
//                    }
//                }
//            }
//        }
//    }
    int N=n;
    for (int i1=0; i1<N; i1++)
        for (int j1=0; j1<N; j1++)
            for (int i2=i1; i2<N; i2++)
                for (int j2=j1; j2<N; j2++)
                    if (is_PCL(i1,j1,i2,j2)) {
                        PCL p = {i1,j1,i2,j2};
                        V.push_back(p);
                    }
//    for (int i=0;i<pcls.size();i++){
//        bool ok=true;
//        for (int j=0;j<pcls.size();j++){
//            if (i==j) continue;
//            auto a=pcls[i];
//            auto b=pcls[j];
//            if (a.f.f>=b.f.f&&a.f.s<=b.f.s&&a.s.f>=b.s.f&&a.s.s<=b.s.s) ok=false;
//        }
//        if (ok) ans++;
//    }
    for (int i=0; i<V.size(); i++)
        if (PCL_maximal(i)) ans++;
    cout<<ans<<endl;
    return 0;
}