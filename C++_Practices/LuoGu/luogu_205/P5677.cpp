//
// Created by thedyingkai_ on 2025/2/22.
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
template<class T> void Sore(vector<T> &v){sort(v.begin(),v.end(),[](T x,T y){return x>y;});}bool yneos(bool a,bool upp=false){if(a){cout<<(upp?"YES\n":"Yes\n");}else{cout<<(upp?"NO\n":"No\n");}return a;}
template<class T> void vec_out(vector<T> &p,int ty=0){if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i)cout<<" ";cout<<p[i];}cout<<"\n";}}
template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
template<class T> T vec_sum(vector<T> &a){T ans=T(0);for(auto &x:a) ans+=x;return ans;}int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
template<class T> T square(T a){return a * a;}
int T=1;

ll tree[300005];
ll lowbit(ll x){return x&-x;}
void add(ll x,ll k,ll n){for(;x<=n;x+=lowbit(x)) tree[x]+=k;}
ll sum(ll x){
    ll res=0;
    for(;x;x-=lowbit(x)) res+=tree[x];
    return res;
}
struct Num{
    ll n;
    int i;
}a[300001];
bool cmp(Num a1,Num a2){return a1.n<a2.n;}
struct Pair{
    int l,r;
}pi[600002];
int pcnt=0;
void addp(Num a1,Num a2){
    int l=min(a1.i,a2.i),r=max(a1.i,a2.i);
    pi[++pcnt].l=l;
    pi[pcnt].r=r;
    return;
}
bool cmpPair(Pair a1,Pair a2){
    if(a1.r!=a2.r) return a1.r<a2.r;
    else return a1.l<a2.l;
}
struct Qu{
    int l,r,i;
}ques[300001];
bool cmpQu(Qu a1,Qu a2){
    if(a1.r!=a2.r)	return a1.r<a2.r;
    else return a1.l<a2.l;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    if(n==1){
        cout<<0;
        return;
    }
    rep(i,1,n) cin>>a[i].n,a[i].i=i;
    sort(a+1,a+1+n,cmp);
    addp(a[1],a[2]);
    addp(a[n],a[n-1]);
    rep(i,2,n-1){
        int l=a[i].n-a[i-1].n,r=a[i+1].n-a[i].n;
        if(l<r) addp(a[i],a[i-1]);
        else if(l==r)	addp(a[i],a[i-1]),addp(a[i],a[i+1]);
        else addp(a[i],a[i+1]);
    }
    sort(pi+1,pi+1+pcnt,cmpPair);
    rep(i,1,m){
        cin>>ques[i].l>>ques[i].r;
        ques[i].i=i;
    }
    sort(ques+1,ques+1+m,cmpQu);
    ll ans=0;
    for(int i=1,j=1;i<=m;i++){
        while(pi[j].r<=ques[i].r&&j<=pcnt){
            add(pi[j].l,1,n);
            j++;
        }
        ans+=1ll*ques[i].i*(j-1-sum(ques[i].l-1));
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
