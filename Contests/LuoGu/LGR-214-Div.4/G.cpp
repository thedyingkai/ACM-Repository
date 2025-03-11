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
void solve() {
    char x[60];
    cin.getline(x,60);
    int a[16]={0};
    int c=0;
    bool d=false;
    int p=-1;
    for(int i=0;i<strlen(x);++i){
        if(x[i]==':'){
            if(i>0&&x[i-1]==':'){
                d=true;
                p=c;
            }
        }
        else{
            int v=0;
            if(x[i]>='A'&&x[i]<='F') v=10+x[i]-'A';
            else if(x[i]>='a'&&x[i]<='f') v=10+x[i]-'a';
            else v=x[i]-'0';
            if(c<8) a[c]=(a[c]<<4)|v;
        }
        if(x[i]==':'||i==strlen(x)-1) c++;
    }
    if(d){
        int z=8-c;
        for(int i=7;i>p+z;--i) a[i]=a[i-z];
        memset(a+p+1,0,z);
    }
    rep(i,0,7) dep(j,15,0) cout<<((a[i]>>j)&1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (T != 1) cin >> T;
    while (T--) solve();
    return 0;
}
