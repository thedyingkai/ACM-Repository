//
// Created by thedyingkai_ on 2025/2/15.
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

void solve() {
    ll n,c1=0,i1=0,c2=0,i2=0,ans=1e18;
    string s;
    cin>>n>>s;
    s=' '+s;
    vector<ll> v(n+1);
    rep(i,1,n){
        if(s[i]=='1') c1++;
        else i1+=c1;
        v[i]=i1;
//        dbg(s[i]),dbg(i),dbg(i1),dbg(c1),dbg(v[i]);
//        cout<<endl;
    }
    dep(i,n,1){
        if(s[i]=='1') c2++;
        else i2+=c2;
        ans=min(ans,v[i]+i2);
//        dbg(s[i]),dbg(i),dbg(i2),dbg(c2);
//        cout<<endl;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
