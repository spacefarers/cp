/*
ID: michael419
LANG: C++
TASK: heritage
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct node{
    int val;
    node *right, *left, *parent;
    void link_left(node *n){
        this->left=n;
        n->parent=this;
    }
    void link_right(node *n){
        this->right=n;
        n->parent=this;
    }
};

string a, b;
int where[30];
node nodes[30];
bool vis[30];

void solve(node *x){
    if (x==nullptr) return;
    solve(x->left);
    solve(x->right);
    cout<<(char)(x->val+'A');
}

int main(){
    setIO("heritage");
    cin>>a>>b;
    for (int i=0;i<a.size();i++){
        where[a[i]-'A']=i;
    }
    node *root=&nodes[where[b[0]-'A']];
    root->val=b[0]-'A';
    node *last_node=root;
    vis[where[b[0]-'A']]=true;
    int last_where=where[b[0]-'A'];
    for (int i=1;i<b.size();i++){
        int pos=where[b[i]-'A'];
        node *new_node=&nodes[pos];
        new_node->val=b[i]-'A';
        if (pos<last_where){
            last_node->link_left(new_node);
        } else {
            int u=pos;
            while (!vis[u]) u--;
            nodes[u].link_right(new_node);
        }
        last_node=new_node;
        vis[pos]=true;
        last_where=pos;
    }
    solve(root);
    cout<<endl;
}