/*
ID: michael419
LANG: C++
TASK: preface
*/

#include <iostream>
#include <vector>

using namespace std;

#define f first
#define s second

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int ans[7]; //0:1 1:5 2:10 3:50 4:100 5:500 6:1000

void solve(int x){
    int ones=x%10;
    x/=10;
    int tens=x%10;
    x/=10;
    int hundreds=x%10;
    x/=10;
    int thousands=x;
    ans[6]+=thousands;
    if (hundreds>0){
        if (hundreds>=5&&hundreds<9) {
            hundreds-=5;
            ans[5]++;
        } else if (hundreds==9){
            hundreds-=9;
            ans[6]++;
            ans[4]++;
        }
        if (hundreds<4) ans[4]+=hundreds;
        else if (hundreds==4){
            ans[4]++;ans[5]++;
        }
    }
    if (tens>0){
        if (tens>=5&&tens<9) {
            tens-=5;
            ans[3]++;
        } else if (tens==9){
            tens-=9;
            ans[4]++;
            ans[2]++;
        }
        if (tens<4) ans[2]+=tens;
        else if (tens==4){
            ans[2]++;ans[3]++;
        }
    }
    if (ones>0){
        if (ones>=5&&ones<9) {
            ones-=5;
            ans[1]++;
        } else if (ones==9){
            ones-=9;
            ans[2]++;
            ans[0]++;
        }
        if (ones<4) ans[0]+=ones;
        else if (ones==4){
            ans[0]++;ans[1]++;
        }
    }
}

int main(){
    setIO("preface");
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        solve(i);
    }
    if (ans[0]) cout<<"I "<<ans[0]<<endl;
    if (ans[1]) cout<<"V "<<ans[1]<<endl;
    if (ans[2]) cout<<"X "<<ans[2]<<endl;
    if (ans[3]) cout<<"L "<<ans[3]<<endl;
    if (ans[4]) cout<<"C "<<ans[4]<<endl;
    if (ans[5]) cout<<"D "<<ans[5]<<endl;
    if (ans[6]) cout<<"M "<<ans[6]<<endl;
}