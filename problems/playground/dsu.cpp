#include <iostream>

using namespace std;

int father[100005], ranks[100005];

int find(int x){
    if (x!=father[x]) father[x]=find(father[x]);
    return father[x];
}

void unionn(int a, int b){
    int c=find(a);
    int d=find(b);
    if (ranks[c]>ranks[d]) swap(c, d);
    father[c]=d;
    if (ranks[c]==ranks[d]) ranks[d]++;
}

int main(){

}