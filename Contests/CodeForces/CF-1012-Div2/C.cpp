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

struct st{
    int x,y,nxt,dist;
    pair<int,int> vis;
};
pair<int,int> gin(int x,int y,int I){
    if(I==0) return {3*x+1,3*y+1};
    if(I==1) return {3*x+1,3*y+2};
    if(I==2) return {3*x+2,3*y+1};
    return {3*x+2,3*y+2};
}
vector<st> tb;
int S=320;
struct cmp1{
    bool operator()(int i,int j) const{
        const st &A=tb[i],&B=tb[j];
        if(A.dist!=B.dist) return A.dist<B.dist;
        if(A.vis.first!=B.vis.first) return A.vis.first<B.vis.first;
        if(A.vis.second!=B.vis.second) return A.vis.second<B.vis.second;
        if(A.x!=B.x) return A.x<B.x;
        return A.y<B.y;
    }
};
struct cmp2{
    bool operator()(int i,int j) const{
        const st &A=tb[i],&B=tb[j];
        if(A.dist!=B.dist) return A.dist<B.dist;
        if(A.x!=B.x) return A.x<B.x;
        return A.y<B.y;
    }
};
multiset<int,cmp1> alS;
multiset<int,cmp2> emS;
vector<int> cn;
void pre(){
    tb.clear();
    for(int x=0;x<=S;x++) for(int y=0;y<=S-x;y++){
            st tbl;
            tbl.x=x; tbl.y=y;
            tbl.nxt=0;
            tbl.dist=3*(x+y)+2;
            tbl.vis=gin(x,y,0);
            tb.push_back(tbl);
        }
    cn.resize(tb.size());
    for(int i=0;i<(int)tb.size();i++) cn[i]=i;
    sort(cn.begin(),cn.end(),[&](int i,int j){
        const st &A=tb[i],&B=tb[j];
        if(A.dist!=B.dist) return A.dist<B.dist;
        if(A.x!=B.x) return A.x<B.x;
        return A.y<B.y;
    });
    for(int idx:cn){
        alS.insert(idx);
        emS.insert(idx);
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    auto aL=alS;
    auto emL=emS;
    vector<pair<int,int>> ans(n);
    rep(i,0,n-1){
        int type=a[i];
        int chs=-1;
        if(type==1){
            if(!emL.empty()) chs=*emL.begin();
            else chs=*aL.begin();
        }
        else chs=*aL.begin();
        ans[i]=tb[chs].vis;
        aL.erase(aL.find(chs));
        if(tb[chs].nxt==0) emL.erase(emL.find(chs));
        tb[chs].nxt++;
        if(tb[chs].nxt<4){
            tb[chs].vis=gin(tb[chs].x,tb[chs].y,tb[chs].nxt);
            aL.insert(chs);
        }
    }
    for(auto &p:ans) cout<<p.first<<' '<<p.second<<endl;
    for(int idx:cn){
        tb[idx].nxt=0;
        tb[idx].vis=gin(tb[idx].x,tb[idx].y,0);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
    pre();
	while(T--) solve();
	return 0;
}
