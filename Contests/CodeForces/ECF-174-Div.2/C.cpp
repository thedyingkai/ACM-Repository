//
// Created by thedyingkai_ on 2025/2/18.
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
int T=0;

const ll MOD=998244353;
CI M=200005;
vector<ll> pw(M),iv(M);

void pre(){
    pw[0]=1;
    rep(i,1,M-1) pw[i]=(pw[i-1]*2)%MOD;
    iv[0]=1;
    ll inv=(MOD+1)/2;
    rep(i,1,M-1) iv[i]=(iv[i-1]*inv)%MOD;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    rep(i,0,n-1) cin>>arr[i];
    int sz=n+2;
    vector<ll> b1(sz,0),b2(sz,0);
    auto upd=[&](vector<ll>&b,int i,ll v){for(;i<sz;i+=i&-i) b[i]=(b[i]+v)%MOD;};
    auto qry=[&](vector<ll>&b,int i)->ll{ll s=0;for(;i;i-=i&-i) s=(s+b[i])%MOD;return s;};
    ll ans=0;
    int p=0;
    rep(i,0,n-1){
        if(arr[i]==1){
            upd(b1,p+1,1);
            upd(b2,p+1,iv[p]);
        }
        else if(arr[i]==3){
            int x=p;
            if(x>0){
                ll cnt=qry(b1,x),s=qry(b2,x);
                ll cur=(pw[x]*s%MOD-cnt)%MOD;
                if(cur<0) cur+=MOD;
                ans=(ans+cur)%MOD;
            }
        }
        else p++;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
    pre();
	while(T--) solve();
	return 0;
}
