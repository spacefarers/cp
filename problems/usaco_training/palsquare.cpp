/*
ID: michael419
LANG: C++14
TASK: palsquare
*/


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


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

map<int, char> dict;

int poww(int a, int b){
    int ans=1;
    for(int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

string convert_to_base(int base, int num){
    int c=(int)(log(90000)/log(base))+1;
    string ans;
    while (c>=0) {
        int factor=num/poww(base, c);
        ans+=dict[factor];
        num%=poww(base, c);
        c--;
    }
    while (ans[0]=='0') ans=ans.substr(1, ans.size()-1);
    return ans;
}

bool is_pal(const string &a){
    for (int i=0;i<(a.size()+1)/2;i++){
        if (a[i]!=a[a.size()-1-i]) return false;
    }
    return true;
}

int main() {
    setIO("palsquare");
    dict[0]='0';
    dict[1]='1';
    dict[2]='2';
    dict[3]='3';
    dict[4]='4';
    dict[5]='5';
    dict[6]='6';
    dict[7]='7';
    dict[8]='8';
    dict[9]='9';
    dict[10]='A';
    dict[11]='B';
    dict[12]='C';
    dict[13]='D';
    dict[14]='E';
    dict[15]='F';
    dict[16]='G';
    dict[17]='H';
    dict[18]='I';
    dict[19]='J';
    dict[20]='K';
    int n;
    cin>>n;
    for (int i=1;i<=300;i++){
        string sq_base=convert_to_base(n, i*i);
        if (is_pal(sq_base)){
            cout<<convert_to_base(n, i)<<" "<<sq_base<<endl;
        }
    }
    return 0;
}