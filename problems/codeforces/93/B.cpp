// created on 2021/7/9 by spacefarers
// problem: B. End of Exams

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

// fraction struct template
struct fraction{
    ll numerator,denominator;
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



vector<pair<int,fraction>> ans[55];

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    fraction n=fraction(a,1),w=fraction(b,1),m=fraction(c,1);
    fraction each=n*w/m;
    int progress=0;
    fraction filled=fraction(0,1);
    for (int i=1;i<=a;i++){
        if (w<each-filled){
            ans[progress].emplace_back(i,w);
            filled+=w;
        } else if (w==each-filled){
            ans[progress++].emplace_back(i,w);
            filled=fraction(0,1);
        } else {
            ans[progress++].emplace_back(i,each-filled);
            ans[progress].emplace_back(i,w-(each-filled));
            filled=w-(each-filled);
            if (filled==each){
                progress++;
                filled=fraction(0,1);
            } else if (filled>each){
                cout<<"NO"<<endl;
                exit(0);
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<c;i++){
        for (auto j:ans[i]){
            cout<<j.f<<" ";
            printf("%.7f ",double(j.s.numerator)/double(j.s.denominator));
        }
        cout<<endl;
    }
}