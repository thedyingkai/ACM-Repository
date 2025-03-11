//
// Created by thedyingkai_ on 2025/2/23.
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
long long qp(long long a,long long b){
    long long res=1;
    for(;b;b>>=1){
        if(b&1) res*=a;
        a*=a;
    }
    return res;
}
void solve(){
    ll m,k=0,sum=0;
    vector<ll> res;
    cin>>m;
    while(m){
        if(m&1){
            res.push_back(qp(2,k));
            sum++;
        }
        m/=2;
        k++;
    }
    ll re=1,in=0;
    while(re<=sum) re*=2;
//    dbg(re);
//    dbg(sum);
    if(sum-re/2!=0) sum=re-sum;
    else sum=0;
//    dbg(sum);
    Sore(res);
    while(1){
        if(sum==0) break;
        ll x=res.back();
        if(x>1){
            sum--;
            res.erase(res.end());
            res.push_back(x/2);
            res.push_back(x/2);
        }
        else{
            res.erase(res.end());
            in++;
        }
    }
    So(res);
    if(in!=0) rep(i,1,in) cout<<1<<' ';
//    ll check=0,chch=0;
    if(!res.empty()) rep(i,0,res.size()-1){
        cout<<res[i]<<' ';
//        check+=res[i];
//        chch++;
    }
//    cout<<endl<<check+in<<' '<<chch+in<<endl;
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(T!=1) cin>>T;
    while(T--) solve();
    return 0;
}