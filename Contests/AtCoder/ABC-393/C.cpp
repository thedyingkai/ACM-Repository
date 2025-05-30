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
    int n,m;
    cin>>n>>m;
    unordered_set<string> e;
    int ss=0,mm=0;
    rep(i,0,m-1){
        int u,v;
        cin>>u>>v;
        if(u==v){
            ss++;
            continue;
        }
        if(u>v) swap(u,v);
        string s= to_string(u)+","+ to_string(v);
        if(e.find(s)!=e.end()) mm++;
        else e.insert(s);
    }
    cout<<ss+mm;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
