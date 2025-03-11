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
bool w[5050],q[5050];
void solve() {

    int n,k;
    cin>>n>>k;
    int res=0;
    int a[5005];
    rep(i,1,n){
        cin>>a[i];
        if(a[i]>=50) w[i]=0;
        else w[i]=1;
        q[i]=w[i];
    }
    rep(i,1,n-k+1){
        rep(j,1,n) w[j]=q[j];
        int sum=0;
        rep(l,i,min(i+k-1,n)) if(a[l]-2<50) w[l]=1;
        rep(l,1,n) sum+=w[l];
        if(sum*2>n) res++;
    }
    cout<<res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
