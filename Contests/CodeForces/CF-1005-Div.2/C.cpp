//
// Created by thedyingkai_ on 2025/2/17.
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
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}
int T = 0;

void solve() {
    int n;
    cin>>n;
    vector<ll> dp(2);
    rep(i,0,n-1){
        ll a;
        cin>>a;
        if(a<0) dp[1]-=a;
        else dp[0]+=a;
        chmax(dp[1],dp[0]);
    }
    cout<<dp[1]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
