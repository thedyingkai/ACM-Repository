//
// Created by thedyingkai_ on 2025/3/23.
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

bool isPrime[100000];
int Prime[60000],cnt=0;
void prime(int n){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]) Prime[++cnt] = i;
        for(int j = 1; j <= cnt && i*Prime[j] <= n; j++){
            isPrime[i*Prime[j]] = 0;
            if(i % Prime[j] == 0) break;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    rep(i,n/2+1,n){
        if(isPrime[i]){
            cout<<i<<' ';
            int cn=0;
            rep(j,1,n-1){
                if(j&1) cn++;
                if(j&1) cout<<i-cn<<' ';
                else cout<<i+cn<<' ';
            }
            cout<<endl;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    prime(100000);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
