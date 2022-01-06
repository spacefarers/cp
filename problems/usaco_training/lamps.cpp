/*
ID: michael419
LANG: C++
TASK: lamps
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define f first
#define s second

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int n, c;
vector<vector<bool>> opts;
vector<bool> processing;
bool lamps[105];

void generate_bits(){
    if (processing.size()==4){
        opts.push_back(processing);
        return;
    }
    processing.push_back(false);
    generate_bits();
    processing.pop_back();
    processing.push_back(true);
    generate_bits();
    processing.pop_back();
}

void but2(){
    for (int i=1;i<=n;i+=2){
        lamps[i]=!lamps[i];
    }
}

void but3(){
    for (int i=2;i<=n;i+=2){
        lamps[i]=!lamps[i];
    }
}

void but4(){
    for (int i=1;i<=n;i+=3){
        lamps[i]=!lamps[i];
    }
}

int main(){
    setIO("lamps");
    cin>>n>>c;
    vector<int> final_on, final_off;
    while (true){
        int x;
        cin>>x;
        if (x==-1) break;
        final_on.push_back(x);
    }
    while (true){
        int x;
        cin>>x;
        if (x==-1) break;
        final_off.push_back(x);
    }
    generate_bits();
    vector<string> ans;
    for (auto &i:opts){
        int x=0;
        for (auto &&j:i){
            if (j) x++;
        }
        if (c-x<0||(c-x)%2) continue;
        memset(lamps, !i[0], sizeof lamps);
        if (i[1]) but2();
        if (i[2]) but3();
        if (i[3]) but4();
        for (auto &j:final_on){
            if (!lamps[j]) goto cont;
        }
        for (auto &j:final_off){
            if (lamps[j]) goto cont;
        }
        if (false){
            cont:;
            continue;
        }
        string c_ans;
        for (int j=1;j<=n;j++){
            if (lamps[j]) c_ans+='1';
            else c_ans+='0';
        }
        ans.push_back(c_ans);
    }
    sort(ans.begin(), ans.end());
    for (auto &i:ans){
        cout<<i<<endl;
    }
    if (ans.empty()){
        cout<<"IMPOSSIBLE"<<endl;
    }
}