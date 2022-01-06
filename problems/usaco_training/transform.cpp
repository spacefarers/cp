/*
ID: michael419
LANG: C++
TASK: transform
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
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


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n;
bool check_same(const vector<vector<char>> &a, const vector<vector<char>> &b){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (a[i][j]!=b[i][j]) return false;
        }
    }
    return true;
}

void debug_print(const vector<vector<char>> &a){
    trav(i, a){
        trav(j, i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

vector<vector<char>> reflect(const vector<vector<char>> &a){
    vector<vector<char>> ans;
    for (int j=0;j<n;j++){
        vector<char> temp;
        for (int i=n-1;i>=0;i--){
            temp.pb(a[j][i]);
        }
        ans.pb(temp);
    }
    return ans;
}

vector<vector<char>> rotate_90(const vector<vector<char>> &a){
    vector<vector<char>> ans;
    for (int j=0;j<n;j++){
        vector<char> temp;
        for (int i=n-1;i>=0;i--){
            temp.pb(a[i][j]);
        }
        ans.pb(temp);
    }
    return ans;
}

int main() {
    setIO("transform");
    cin>>n;
    vector<vector<char>> board1, board2;
    board1.rsz(n);
    board2.rsz(n);
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        board1[i].rsz(n);
        for (int j=0;j<n;j++){
            board1[i][j]=a[j];
        }
    }
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        board2[i].rsz(n);
        for (int j=0;j<n;j++){
            board2[i][j]=a[j];
        }
    }
    auto board3 = rotate_90(board1);
    auto board4 = rotate_90(board3);
    auto board5 = rotate_90(board4);
    if (check_same(board2, board3)){
        cout<<1<<endl;
        return 0;
    } else if (check_same(board4, board2)){
        cout<<2<<endl;
        return 0;
    } else if (check_same(board5, board2)){
        cout<<3<<endl;
        return 0;
    }
    auto board6=reflect(board1);
    if (check_same(board6, board2)){
        cout<<4<<endl;
        return 0;
    }
    board3 = rotate_90(board6);
    board4 = rotate_90(board3);
    board5 = rotate_90(board4);
    if (check_same(board2, board3)||check_same(board4, board2)||check_same(board5, board2)){
        cout<<5<<endl;
        return 0;
    }
    if (check_same(board1, board2)) {
        cout<<6<<endl;
        return 0;
    }
    cout<<7<<endl;
    return 0;
}