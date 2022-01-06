#include <iostream>

using namespace std;

int n, a[10005], b[10005], c[10005], d[10005], x, y;

int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    cin>>x>>y;
    for (int i=n;i>=1;i--){
        if (x>=a[i]&&x<=c[i]+a[i]&&y>=b[i]&&y<=d[i]+b[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
