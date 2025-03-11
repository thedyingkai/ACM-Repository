//
// Created by thedyingkai_ on 2025/2/14.
//
#include <bits/stdc++.h>

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
int n,m,mx,my,tx[9]={-1,-2,1,2,-1,-2,1,2,0},ty[9]={-2,-1,2,1,2,1,-2,-1,0};
ll Map[24][24];
void solve() {
    cin>>n>>m>>mx>>my;
    n++,m++,mx++,my++;
    mem(Map,0);
    rep(i,1,n) rep(j,1,m) Map[i][j]=1;
    rep(i,1,n) rep(j,1,m) rep(k,0,8) if(i==mx+tx[k]&&j==my+ty[k]) Map[i][j]=0;
//    rep(j,1,n){
//        aout(Map[j],m)<<' ';
//        cout<<endl;
//    }
//    cout<<endl;
    dep(i,n-1,1) dep(j,m-1,1) if(Map[i][j]!=0) Map[i][j]=Map[i+1][j]+Map[i][j+1];
//    rep(j,1,n){
//        aout(Map[j],m)<<' ';
//        cout<<endl;
//    }
    cout<<Map[1][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}