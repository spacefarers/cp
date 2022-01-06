#include <iostream>

using namespace std;

int x[100005], b[100005], n=0;

int main(){
    while(true){
        char a = getchar();
        if (a==10) break;
        else if (a==32) continue;
        x[++n] = a-'0';
        cout<<n<<endl;
    }
    b[1] = 1;
    for (int i=2;i<=n;i++){
        int best=0;
        for (int j=1;j<i;j++){
            if (x[j]>=x[i])
                best = max(best, b[j]+1);
        }
        b[i] = best;
    }
    for (int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
}
