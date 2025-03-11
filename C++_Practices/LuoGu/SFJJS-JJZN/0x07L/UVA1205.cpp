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
int T = 1,r,n;
struct st{
    int f,c,n;
    double val;
}nd[1111];
int f(){
    int ans;
    double Max=0;
    rep(i,1,n) if(i!=r&&nd[i].val>Max){
        Max=nd[i].val;
        ans=i;
    }
    return ans;
}
void solve() {
    int now,ans,a,b,fa;
    cin>>n>>r;
    while(n||r){
        ans=0;
        rep(i,1,n){
            cin>>nd[i].c;
            nd[i].val=nd[i].c;
            nd[i].n=1;
            ans+=nd[i].c;
        }
        rep(i,1,n-1){
            cin>>a>>b;
            nd[b].f=a;
        }
        rep(i,1,n-1){
            now=f();
            nd[now].val=0;
            fa=nd[now].f;
            ans+=nd[now].c*nd[fa].n;
            rep(j,1,n) if(nd[j].f==now) nd[j].f=fa;
            nd[fa].c+=nd[now].c;
            nd[fa].n+=nd[now].n;
            nd[fa].val=double(nd[fa].c)/nd[fa].n;
        }
        cout<<ans<<endl;
        cin>>n>>r;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}