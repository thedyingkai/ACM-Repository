//
// Created by thedyingkai_ on 2025/2/13.
//
#include <bits/stdc++.h>
#include "cstring"

#define dbg(x) std::cout<<#x<<":"<<x<<" "
#define endl "\n"
#define Dcmp(x) greater<#x>
#define YES std::cout<<"YES"<<endl
#define Yes std::cout<<"Yes"<<endl
#define NO std::cout<<"NO"<<endl
#define No std::cout<<"No"<<endl
#define aout(a, n) rep(i,1,n)std::cout<<a[i]
#define ain(a, n) rep(i,1,n)std::cin>>a[i]
#define rep(i, x, n) for(int i=x;i<=n;i++)
#define dep(i, x, n) for(int i=x;i>=n;i--)
#define mem(a, x) memset(a,x,sizeof a)
#define all(x) x.begin(),x.end()
#define arrall(a, n) a+1,a+1+n
#define PII std::pair<int,int>
#define m_p std::make_pair
#define ff first
#define ss second
#define CD const double
#define CI const int
#define ll long long
using namespace std;
int T = 1;
int m[10]={6,2,5,5,4,5,6,3,7,6};
int val(int x){
    int sum=0;
    string a=to_string(x);
    rep(i,0,a.length()-1) sum+=m[a[i]-'0'];
    return sum;
}
void solve() {
    int n;
    cin>>n;
    n-=4;
    int sum=0;
    rep(i,0,10000){
        rep(j,0,1000){
            if(val(i)+val(j)+val(i+j)==n) sum++;
        }
    }
    cout<<sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
