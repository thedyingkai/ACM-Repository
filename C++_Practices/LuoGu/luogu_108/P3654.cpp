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
int T = 1,sum=0,k;
bool m[102][102];
void dfs(int i,int x,int y,int to){
    if(!m[x][y]) return;
    if(i==k){
        sum++;
        return;
    }
    if(to==1) dfs(i+1,x+1,y,1);
    if(to==3) dfs(i+1,x,y+1,3);
}
void solve() {
    int r,c;
    mem(m,0);
    cin>>r>>c>>k;
    char ch;
    rep(i,1,r) rep(j,1,c){
        cin>>ch;
        if(ch=='.') m[i][j]=1;
    }
    rep(i,1,r) rep(j,1,c){
        dfs(1,i,j,1);
        dfs(1,i,j,3);
    }
    if(k==1) sum/=2;
    cout<<sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
