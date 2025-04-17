//
// Created by thedyingkai_ on 2025/4/9.
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

constexpr int N=200000*31;
int tot;
int cnt[N];
int trie[N][2];
int newNode(){
    int x=++tot;
    trie[x][0]=trie[x][1]=0;
    cnt[x]=0;
    return x;
}
void add(int x,int t){
    int tem=1;
    dep(i,29,0){
        int &p=trie[tem][x>>i&1];
        if(!p) p=newNode();
        tem=p;
        cnt[tem]+=t;
    }
}
int query(int x){
    int tem=1,res=0;
    dep(i,29,0){
        int d=x>>i&1;
        if(cnt[trie[tem][d^1]]){
            d^=1;
            res|=1<<i;
        }
        tem=trie[tem][d];
    }
    return res;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    tot=0;
    newNode();
    int ans=n+1;
    for(int i=0,j=0;i<n;i++){
        add(a[i],1);
        while(j<=i&&query(a[i])>=k){
            ans=min(ans,i-j+1);
            add(a[j],-1);
            j++;
        }
    }
    if(ans>n) ans=-1;
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
