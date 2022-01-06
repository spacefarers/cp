#include <iostream>
#include <map>

using namespace std;

long long mp[26];

int main(){
    string a;
    cin>>a;
    for (char i : a) {
        mp[i-'A']++;
    }
    int mid=-1;
    string ans, f_ans;
    for (int i=0;i<26;i++){
        if (mp[i]%2==1&&mid==-1) {
            mid=i;
            mp[i]--;
        }
        if (mp[i]%2==1) {
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
        if (mp[i]==0) continue;
        for (int j=0;j<mp[i]/2;j++) ans+=(char)i+'A';
    }
    f_ans=ans;
    if (mid!=-1)
        f_ans+=(char)mid+'A';
    for (int i=(int)ans.size()-1;i>=0;i--)
        f_ans+=ans[i];
    cout<<f_ans<<endl;
}