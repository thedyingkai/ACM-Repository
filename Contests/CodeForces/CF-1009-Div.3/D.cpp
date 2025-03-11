//
// Created by thedyingkai_ on 2025/3/11.
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

ll fuck(vector<pair<ll,ll>>& in){
    if(in.empty()) return 0;
    So(in);
    ll res=0;
    ll L=in[0].first;
    ll R=in[0].second;
    for(size_t i = 1; i<in.size(); ++i){
        ll l=in[i].first;
        ll r=in[i].second;
        if(l<=R+1) R=max(R,r);
        else{
            res+=R-L+1;
            L=l;
            R=r;
        }
    }
    res+=R-L+1;
    return res;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> c(n),r(n);
    ll maxr=0;
    rep(i,0,n-1) cin>>c[i];
    rep(i,0,n-1) cin>>r[i],maxr=max(maxr,r[i]);
    vector<vector<pair<ll,ll>>> yy(maxr+1);
    rep(i,0,n-1){
        rep(j,0,r[i]){
            if(j*j>r[i]*r[i]) continue;
            ll tar=r[i]*r[i]-j*j;
            ll L=0,R=r[i],dx=0;
            while(L<=R){
                ll mid=(L+R)/2;
                if(mid*mid<=tar){
                    dx=mid;
                    L=mid+1;
                }
                else R=mid-1;
            }
            yy[j].emplace_back(c[i]-dx,c[i]+dx);
        }
    }
    ll tot=0;
    rep(i,0,maxr){
        if(yy[i].empty()) continue;
        ll sum=fuck(yy[i]);
        if(i==0) tot+=sum;
        else tot+=2*sum;
    }
    cout<<tot<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
