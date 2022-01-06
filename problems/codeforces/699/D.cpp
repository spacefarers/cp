#include <iostream>
#include <cstring>

using namespace std;

string board[1005];
int has[1005][2];
int n, m;


void solve(){
    if (m%2){
        cout<<"YES"<<endl;
        for (int i=0;i<=m/2;i++){
            cout<<1<<" "<<2<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (board[i][j]==board[j][i]){
                cout<<"YES"<<endl;
                for (int k=0;k<m/2;k++){
                    cout<<i+1<<" "<<j+1<<" ";
                }
                cout<<i+1;
                cout<<endl;
                return;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==j) continue;
            if (board[i][j]=='*') continue;
            if (has[j][board[i][j]-'a']!=-1){
                int k=has[j][board[i][j]-'a'];
                cout<<"YES"<<endl;
                if (m%4){
                    for (int l=0;l<m/4;l++){
                        cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<j+1<<" ";
                    }
                    cout<<i+1<<" "<<j+1<<" "<<k+1;
                } else {
                    for (int l=0;l<m/4;l++){
                        cout<<j+1<<" "<<k+1<<" "<<j+1<<" "<<i+1<<" ";
                    }
                    cout<<j+1;
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(has, -1, sizeof has);
        cin>>n>>m;
        for (int i=0;i<n;i++){
            cin>>board[i];
            for (int j=0;j<n;j++){
                if (board[i][j]=='*') continue;
                has[i][board[i][j]-'a']=j;
            }
        }
        solve();
    }
}