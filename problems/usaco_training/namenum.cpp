/*
ID: michael419
LANG: C++14
TASK: namenum
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
string n;
vector<string> accepts;
int c=0;
bool ok=false;
map<int, string> dict;

int poww(int a, int b){
    int ans=1;
    for (int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

void generate_pos(int i, int one, const string &left){
    string temp=left;
    temp+=dict[n[i]-'0'][one];
    if (i==n.size()-1){
        while (strcmp(accepts[c].c_str(), temp.c_str())<0){
            c++;
        }
        if (strcmp(accepts[c].c_str(), temp.c_str())==0){
            cout<<accepts[c]<<endl;
            ok=true;
            c++;
        }
        return;
    }
    generate_pos(i+1, 0, temp);
    generate_pos(i+1, 1, temp);
    generate_pos(i+1, 2, temp);
}

int main() {
    setIO("namenum");
    dict[2]="ABC";
    dict[3]="DEF";
    dict[4]="GHI";
    dict[5]="JKL";
    dict[6]="MNO";
    dict[7]="PRS";
    dict[8]="TUV";
    dict[9]="WXY";
    ifstream myReadFile;
    myReadFile.open("dict.txt");
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            string a;
            myReadFile>>a;
            accepts.pb(a);
        }
    }
    myReadFile.close();
    cin>>n;
    generate_pos(0, 0, "");
    generate_pos(0, 1, "");
    generate_pos(0, 2, "");
    if (!ok) cout<<"NONE"<<endl;
    return 0;
}