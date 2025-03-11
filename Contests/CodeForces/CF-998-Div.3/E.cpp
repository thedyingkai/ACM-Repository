//
// Created by thedyingkai_ on 2025/3/9.
// @formatter:off
#include <bits/stdc++.h>
#define dbg(x) std::cout<<#x<<":"<<x<<" "
#define endl "\n"
#define Dcmp(x) greater<#x>
#define YES std::cout<<"YES"<<endl
#define Yes std::cout<<"Yes"<<endl
#define NO std::cout<<"NO"<<endl
#define No std::cout<<"No"<<endl
#define aout(a,n) rep(i,1,n)std::cout<<a[i]
#define ain(a,n) rep(i,1,n)std::cin>>a[i]
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define mem(a,x) memset(a,x,sizeof a)
#define CD const double
#define CI const int
#define ll long long
#define ld long double
using namespace std;
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> int LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> int UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,T b){if(b<a){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v){sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v){sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void vec_out(vector<T> &p,int ty=0){if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i)cout<<" ";cout<<p[i];}cout<<"\n";}}
template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
template<class T> T vec_sum(vector<T> &a){T ans=T(0);for(auto &x:a) ans+=x;return ans;}int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
template<class T> T square(T a){return a * a;}
int T=0;

struct st{
    int u,v;
    int fa;
    int i;
}e1[200005],e2[200005];
int find(int x,st* a){
    if(a[x].fa==x) return x;
    return a[x].fa=find(a[x].fa,a);
}
void solve(){
    int n,m1,m2,res=0,cntf=0,cntg=0;
    cin>>n>>m1>>m2;
    rep(i,1,n) e1[i].fa=i,e2[i].fa=i;
    rep(i,1,m1){
        int u,v; cin>>u>>v;
        e1[i].u=u,e1[i].v=v,e1[i].i=i;
    }
    rep(i,1,m2){
        int u,v; cin>>u>>v;
        int fx=find(u,e2),fy=find(v,e2);
        if(fx!=fy) e2[fx].fa=fy;
    }
    rep(i,1,m1){
        if(find(e1[i].u,e2)==find(e1[i].v,e2)){
            int fx=find(e1[i].u,e1),fy=find(e1[i].v,e1);
            e1[fx].fa=fy;
        }
        else res++;
    }
    rep(i,1,n){
        if(e1[i].fa==i) cntf++;
        if(e2[i].fa==i) cntg++;
    }
    cout<<res+cntf-cntg<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
