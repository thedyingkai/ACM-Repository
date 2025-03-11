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
struct st{
    int a[5000];
    int i;
};
st add(st a,st b){
    int ii=max(a.i,b.i);
    rep(i,0,ii-1){
        a.a[i]+=b.a[i];
        if(a.a[i]>9){
            a.a[i]-=10;
            a.a[i+1]++;
            if(i==ii-1) ii++;
        }
    }
    a.i=ii;
    return a;
}
void solve() {
    int n;
    cin>>n;
    st a[3];
    a[0].a[0]=0,a[1].a[0]=1,a[2].a[0]=1,a[0].i=1,a[1].i=1,a[2].i=1;
    rep(i,3,n+1) a[i%3]=add(a[(i+2)%3],a[(i+1)%3]);
    dep(i,a[(n+1)%3].i-1,0) cout<<(int)a[(n+1)%3].a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
