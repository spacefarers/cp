//
// Created by spacefarers on 4:00 PM Nov 24 2021.
// Problem: D. Bag of mice

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

ll gcd(ll a, ll b){
	if (b==0) return a;
	return gcd(b, a%b);
}

struct fraction{
	ll numerator=0,denominator=1;
	fraction()= default;
	fraction(ll a,ll b){
		numerator=a,denominator=b;
	}
	void simplify(){
		ll gcd_both=gcd(numerator,denominator);
		numerator/=gcd_both;
		denominator/=gcd_both;
	}
	void operator+=(fraction a){
		ll new_denom=denominator*a.denominator;
		ll new_num=numerator*a.denominator+a.numerator*denominator;
		numerator=new_num;
		denominator=new_denom;
		simplify();
	}
	fraction operator+(fraction a){
		fraction ans=*this;
		ans+=a;
		return ans;
	}
	void operator-=(fraction a){
		a.numerator*=-1;
		*this+=a;
	}
	bool operator>(fraction a) const{
		return numerator*a.denominator>a.numerator*denominator;
	}
	bool operator==(fraction a) const{
		return numerator*a.denominator==a.numerator*denominator;
	}
	bool operator<(fraction a) const{
		return numerator*a.denominator<a.numerator*denominator;
	}
	fraction operator*(fraction a) const{
		fraction ans(numerator*a.numerator,denominator*a.denominator);
		ans.simplify();
		return ans;
	}
	fraction operator/(fraction a) const{
		fraction ans(numerator*a.denominator,denominator*a.numerator);
		ans.simplify();
		return ans;
	}
	fraction operator-(fraction a) const{
		fraction ans=*this;
		ans-=a;
		return ans;
	}
};

double dp[1005][1005];

double find(int i,int j){
	if (dp[i][j]!=0) return dp[i][j];
	double dragonBlack,jumpOutWhiteWin,jumpOutBlackWin;
	if (j-1<0||i+j-1==0) dragonBlack=0;
	else dragonBlack=double(j)/(i+j)*double(j-1)/(i+j-1);
	if (j-2<0||i-1<0) jumpOutWhiteWin=0;
	else jumpOutWhiteWin=double(i)/(i+j-2)*find(i-1,j-2);
	if (j-3<0) jumpOutBlackWin=0;
	else jumpOutBlackWin=double(j-2)/(i+j-2)*find(i,j-3);
	if (i+j!=0) dp[i][j]=double(i)/(i+j)+dragonBlack*(jumpOutWhiteWin+jumpOutBlackWin);
	return dp[i][j];
}

int main(){
	fastio
	int w,b;
	cin>>w>>b;
	dp[0][0]=0;
	find(w,b);
	printf("%.9f",dp[w][b]);
}

