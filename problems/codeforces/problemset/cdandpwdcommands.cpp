#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;
	string currentPath = "/";
	for (int i=0; i<n; i++){
		string cmd;
		cin>>cmd;
		if (cmd == "cd"){
			string path;
			cin>>path;
			if (strncmp(path[0], "/", 1)==0){
				currentPath = path;
			} else {
				string tmpDir = "";
				for (int j = 0; j<path.length();j++){
					if (strncmp(path[j], ".", 1) == 0){
						for (int backNum = 0;strncmp(currentPath[currentPath.length()-1-backNum], "/", 1) == 0;backNum++){}
						currentPath = currentPath.substr(0, currentPath.length()-backNum);
						j++;
					} else if (strncmp(path[j], "/", 1) == 0){
						if (tmpDir != ""){
							currentPath += ("/"+tmpDir);
							tmpDir = "";
						}
					} else
						tmpDir += path[j];
				}
			}
		} else {
			cout<<currentPath<<endl;
		}
	}
	return 0;
}
			
