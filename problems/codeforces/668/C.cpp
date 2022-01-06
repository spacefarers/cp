#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int test_cases;
    cin>>test_cases;
    for (int i=1;i<=test_cases;i++){
        int n, k;
        string a;
        bool ok=true;
        cin>>n>>k>>a;
        int q_count=0, q_places[505], q_start=0, q_sums[505][505];
        bool visited[505];
        memset(visited, false, sizeof(visited));
        memset(q_sums, 0x7f, sizeof(q_sums));
        for(int j=0;j<=n-k;j++){
            int all_sum=0;
            for (int b=j;b<j+k;b++){
                if (a[b] == '?'){
                    if (q_sums[b][b]<1000000) all_sum+=q_sums[b][b];
                    if (visited[b]) continue;
                    visited[b] = true;
                    q_places[q_count] = b;
                    q_count++;
                } else if (a[b] == '1'){
                    all_sum+=1;
                } else {
                    all_sum-=1;
                }
            }
            if (q_sums[q_start][q_count]<1000000&&q_sums[q_start][q_count]!=all_sum){
                cout<<"NO!!"<<endl;
                ok=false;
                break;
            }
            if (q_count-q_start<abs(all_sum)||(q_count-q_start-abs(all_sum))%2==1){
                cout<<"NO"<<q_count-q_start<<endl;
                ok=false;
                break;
            } else {
                q_sums[q_start][q_count] = all_sum;
            }
            if (a[j]=='?') q_start++;
        }
        if (ok) cout<<"YES"<<endl;
    }
}
//1
//3 2
//1?1