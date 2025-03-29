//
// Created by thedyingkai_ on 2025/3/29.
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

void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(n==1) cout<<-1<<endl;
    else{
        int cntI=0,cntT=0,cntL=0;
        rep(i,0,n-1){
            if(s[i]=='L') cntL++;
            else if(s[i]=='I') cntI++;
            else if(s[i]=='T') cntT++;
        }
        int Max=max(max(cntI,cntL),cntT);
        int diL=Max-cntL,diI=Max-cntI,diT=Max-cntT;
        vector<int> ops;
        int cnm=2*n;
        bool fuck=1;
        while((diL>0||diI>0||diT>0)&&ops.size()<(size_t)cnm&&fuck){
            bool sb=0;
            rep(i,0,(int)s.size()-2){
                if(s[i]==s[i+1]) continue;
                char nmsl=[&](char a,char b)->char{
                    if(a!='L'&&b!='L') return 'L';
                    if(a!='I'&&b!='I') return 'I';
                    return 'T';
                }(s[i],s[i+1]);
                if((nmsl=='L'&&diL>0)||(nmsl=='I'&&diI>0)||(nmsl=='T'&&diT>0)){
                    s.insert(s.begin()+i+1,nmsl);
                    ops.push_back(i+1);
                    if(nmsl=='L') diL--;
                    else if(nmsl=='I') diI--;
                    else diT--;
                    sb=1;
                    break;
                }
            }
            if(!sb) break;
        }
        if(diL==diI&&diI==diT&&diT==0){
            cout<<ops.size()<<endl;
            for(auto it:ops) cout<<it<<endl;
        }
        else cout<<-1<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
