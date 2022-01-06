#include <iostream>

using namespace std;

int reflections[10]={0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int h, m;

bool valid(int hour, int minute){
	int b=hour%10, d=minute%10, a=hour/10, c=minute/10;
	a=reflections[a];
	b=reflections[b];
	c=reflections[c];
	d=reflections[d];
	if (a==-1||b==-1||c==-1||d==-1) return false;
	if (b*10+a>=m) return false;
	if (d*10+c>=h) return false;
	return true;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>h>>m;
		string a;
		cin>>a;
		int hour=stoi(a.substr(0, 2)), minute=stoi(a.substr(3, 2));
		while (!valid(hour, minute)){
			minute++;
			if (minute==m){
				hour++;
				minute=0;
			}
			if (hour==h){
				hour=0;
			}
		}
		string x, y;
		x=to_string(hour);
		y=to_string(minute);
		if (x.length()==1) x='0'+x;
		if (y.length()==1) y='0'+y;
		cout<<x<<":"<<y<<endl;
	}
}