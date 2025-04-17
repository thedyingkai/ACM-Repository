//
// Created by thedyingkai_ on 2025/4/5.
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

inline ll makeKey(int x, int y){return ((ll)x << 32) | (unsigned int)y;}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,0,n-1) cin >> a[i];
    rep(i,0,n-1) cin >> b[i];
    vector<int> sym,nonSym;
    rep(i,0,n-1){
        if(a[i] == b[i]) sym.push_back(i);
        else nonSym.push_back(i);
    }
    if(n % 2 == 0){
        if(!sym.empty()){
            cout << -1 << "\n";
            return;
        }
    } else {
        if(sym.size() != 1){
            cout << -1 << "\n";
            return;
        }
    }
    unordered_map<ll,int> mp;
    mp.reserve(nonSym.size() * 2);
    vector<bool> used(n);
    for (int i : nonSym) {
        ll key = makeKey(a[i], b[i]);
        mp[key] = i;
    }
    vector<pair<int,int>> pairedNonSym;
    bool possible = 1;
    for (int i : nonSym) {
        if(used[i]) continue;
        long long comp = makeKey(b[i], a[i]);
        if(mp.find(comp) == mp.end()){
            possible = 0;
            break;
        }
        int j = mp[comp];
        if(i == j || used[j]){
            possible = 0;
            break;
        }
        used[i] = 1;
        used[j] = 1;
        pairedNonSym.push_back({i, j});
    }
    if(!possible){
        cout << -1 << "\n";
        return;
    }
    vector<int> Q(n, -1);
    int L = 0, R = n - 1;
    for(auto &pr : pairedNonSym){
        Q[L++] = pr.first;
        Q[R--] = pr.second;
    }
    if(n % 2 == 1){
        Q[L] = sym[0];
    }
    vector<int> cur(n);
    for (int i = 0; i < n; i++){
        cur[i] = i;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++){
        pos[cur[i]] = i;
    }
    vector<pair<int,int>> ops;
    for (int i = 0; i < n; i++){
        if(cur[i] == Q[i]) continue;
        int targetIndex = pos[Q[i]];
        swap(cur[i], cur[targetIndex]);
        pos[cur[i]] = i;
        pos[cur[targetIndex]] = targetIndex;
        ops.push_back({i+1, targetIndex+1});
    }
    cout << ops.size() << "\n";
    for(auto &op : ops){
        cout << op.first << " " << op.second << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
