/*
ID: michael419
LANG: C++
TASK: lineup
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string cows[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<pair<string, string> > constraints;

int where(const string& a){
    for (int i=0;i<8;i++)
        if (a == cows[i])
            return i;
    return -1;
}

int main() {
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");
    int n;
    fin>>n;
    for (int i=0;i<n;i++){
        string a, b, c, d, e, f;
        fin>>a>>b>>c>>d>>e>>f;
        constraints.emplace_back(a, f);
    }
    do {
        bool ok=true;
        for (auto & constraint : constraints){
            if (abs(where(constraint.first)-where(constraint.second))!=1){
                ok=false;
            }
        }
        if (ok) break;
    } while (next_permutation(cows, cows+8));
    for (auto & cow : cows){
        fout<<cow<<endl;
    }
    return 0;
}
