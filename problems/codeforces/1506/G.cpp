#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool used[26],in_stack[26];
int last[26];

int main(){
	int t;
	cin>>t;
	while (t--){
	    string x;
	    cin>>x;
        memset(last,-1,sizeof last);
        memset(used,false,sizeof used);
        memset(in_stack,false,sizeof in_stack);
        for (int i=0;i<x.size();i++){
            last[x[i]-'a']=i;
        }
        deque<char> pending;
        string ans;
        for (int i=0;i<x.size();i++){
            if (used[x[i]-'a']) continue;
            if (!in_stack[x[i]-'a']){
                while (!pending.empty()&&pending.back()<=x[i]){
                    in_stack[pending.back()-'a']=false;
                    pending.pop_back();
                }
                pending.push_back(x[i]);
                in_stack[x[i]-'a']=true;
            }
            if (i==last[x[i]-'a']){
                while (!pending.empty()&&pending.front()>=x[i]){
                    ans+=pending.front();
                    used[pending.front()-'a']=true;
                    pending.pop_front();
                }
            }
        }
        cout<<ans<<endl;
	}
}