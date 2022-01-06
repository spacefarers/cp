//
// Created by spacefarers on 10:31 PM Nov 20 2021.
// Problem: B. Om Nom and Spiders

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

string board[2005];
int numSpiders[2005][2005];
int n,m,k;

bool checkValid(int i,int j){
	return i>0&&j>0&&i<=n&&j<=m;
}

char getBoard(int i,int j){
	if (!checkValid(i,j)) return false;
	return board[i][j];
}

int main(){
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		cin>>board[i+1];
		board[i+1]="."+board[i+1];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int t=i-1;
			if (getBoard(i-t,j)=='D') numSpiders[i][j]++;
			if (getBoard(i+t,j)=='U') numSpiders[i][j]++;
			if (getBoard(i,j+t)=='L') numSpiders[i][j]++;
			if (getBoard(i,j-t)=='R') numSpiders[i][j]++;
		}
	}
	for (int j=1;j<=m;j++){
		int tot=0;
		for (int i=1;i<=n;i++){
			tot+=numSpiders[i][j];
		}
		cout<<tot<<" ";
	}
}

