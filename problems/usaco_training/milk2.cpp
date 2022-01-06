/*
ID: michael419
LANG: C++14
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<>> q;

int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin>>n;
    for (int i=1;i<=n;i++){
        int a, b;
        fin>>a>>b;
        q.push(make_pair(a, b));
    }
    int reached=q.top().first;
    int cont = 0;
    int max_cont=0;
    int idle = 0;
    while (!q.empty()){
        pair<int, int> u = q.top();
        if (u.first>reached) {
            idle = max(idle, u.first - reached);
            max_cont = max(cont, max_cont);
            cont = (u.second - u.first);
            reached = u.second;
        }
        else if (u.second>reached) {
            cont += (u.second - reached);
            reached = u.second;
        }
        q.pop();
    }
    max_cont = max(max_cont, cont);
    fout<<max_cont<<" "<<idle<<endl;
}