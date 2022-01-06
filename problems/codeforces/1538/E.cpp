#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
//    string x;
//    getline(cin,x);
//    cout<<x<<endl;
//    return 0;
    int t;
	string temp;
	getline(cin,temp);
	t=stoi(temp);
    while (t--){
        int n;
	    getline(cin,temp);
		n=stoi(temp);
        map<string,pair<ll,pair<string,string>>> mp;
        ll ans=0;
        for (int i=0;i<n;i++){
            string input_s;
            getline(cin,input_s);
            string obj;
            for (auto j:input_s){
                if (j==' ') break;
                obj+=j;
            }
            auto set_as=input_s.find(":=");
            if (set_as!=string::npos){
                reverse(input_s.begin(),input_s.end());
                string subj,back_info,front_info;
                for (auto j:input_s){
                    if (j==' ') break;
                    subj+=j;
                }
                reverse(subj.begin(),subj.end());
                if (subj.size()>3) front_info=subj.substr(0,3),back_info=subj.substr(subj.size()-3,3);
                else front_info=subj,back_info=subj;
                int c=0;
                for (int j=0;j<=(int)subj.size()-4;j++){
                    if (subj.substr(j,4)=="haha") c++;
                }
                mp[obj]={c,{front_info,back_info}};
            } else {
                string subj1,subj2;
                int spaces=0;
                for (auto j:input_s){
                    if (j==' ') spaces++;
                    else if (spaces==2) subj1+=j;
                    else if (spaces==4) subj2+=j;
                }
                string piece=mp[subj1].second.second+mp[subj2].second.first;
                int additional=0;
                for (int j=0;j<=(int)piece.size()-4;j++){
                    if (piece.substr(j,4)=="haha") additional++;
                }
                string back_info=mp[subj2].second.second,front_info=mp[subj1].second.first;
                if (front_info.size()<3){
                    front_info+=mp[subj2].second.first;
                    if (front_info.size()>3) front_info=front_info.substr(0,3);
                }
                if (back_info.size()<3){
                    back_info=mp[subj1].second.second+back_info;
                    if (back_info.size()>3) back_info=back_info.substr(back_info.size()-3,3);
                }
                mp[obj]={mp[subj1].first+mp[subj2].first+additional,{front_info,back_info}};
            }
            ans=mp[obj].first;
        }
        cout<<ans<<endl;
    }
}