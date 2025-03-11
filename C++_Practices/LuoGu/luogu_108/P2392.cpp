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
int res[5];
void dfs(int i,int t[],int s,int as,int bs,int n){
    if(i>s){
        int tem=max(as,bs);
        if(tem<res[n]) res[n]=tem;
        return;
    }
    dfs(i+1,t,s,t[i]+as,bs,n);
    dfs(i+1,t,s,as,t[i]+bs,n);
}
void solve() {
    int s1,s2,s3,s4;
    int t1[21],t2[21],t3[21],t4[21];
    cin>>s1>>s2>>s3>>s4;
    mem(res,0x3f);
    rep(i,1,s1) cin>>t1[i];
    rep(i,1,s2) cin>>t2[i];
    rep(i,1,s3) cin>>t3[i];
    rep(i,1,s4) cin>>t4[i];
    dfs(1,t1,s1,0,0,1);
    dfs(1,t2,s2,0,0,2);
    dfs(1,t3,s3,0,0,3);
    dfs(1,t4,s4,0,0,4);
    int sum=0;
    rep(i,1,4) sum+=res[i];
    cout<<sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
