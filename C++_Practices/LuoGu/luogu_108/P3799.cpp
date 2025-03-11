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
CI mod=1e9+7;
void solve() {
    ll n,x,Max=-1,Min=0x3f3f,a[5500];
    mem(a,0);
    cin>>n;
    ll sum=0;
    rep(i,1,n) cin>>x,a[x]++,Max=max(Max,x),Min=min(Min,x);
    rep(i,Min+1,Max) if(a[i]>=2){
        rep(j,Min,i/2) if(a[j]!=0&&a[i-j]!=0){
            if(j!=i-j) sum+=(a[i]*(a[i]-1)*a[j]*a[i-j]/2)%mod;
            else sum+=(a[i]*(a[i]-1)*a[j]*(a[i-j]-1)/4)%mod;
        }
        sum%=mod;
    }
    cout<<sum%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}