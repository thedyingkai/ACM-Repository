//
// Created by thedyingkai_ on 2025/3/26.
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

const int MOD = 998244353;
struct Point {
    int x, y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};
void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    reverse(grid.begin(), grid.end());
    vector<vector<Point>> rows(n);
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        vector<Point> pts;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X') {
                pts.emplace_back(i, j);
            }
        }
        if (pts.empty()) {
            possible = false;
        }
        rows[i] = pts;
    }
    if (!possible) {
        cout << 0 << '\n';
        return;
    }
    vector<array<map<int, int>, 2>> dp(n);
    for (const auto& p : rows[0]) {
        dp[0][0][p.y] = (dp[0][0][p.y] + 1) % MOD;
    }
    if (rows[0].size() >= 2) {
        for (size_t i = 0; i < rows[0].size(); ++i) {
            for (size_t j = i + 1; j < rows[0].size(); ++j) {
                const auto& p1 = rows[0][i];
                const auto& p2 = rows[0][j];
                int dx = p1.x - p2.x;
                int dy = p1.y - p2.y;
                if (dx * dx + dy * dy <= d * d) {
                    dp[0][1][p2.y] = (dp[0][1][p2.y] + 1) % MOD;
                    dp[0][1][p1.y] = (dp[0][1][p1.y] + 1) % MOD;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        const auto& curr_row = rows[i + 1];
        array<map<int, int>, 2> next_dp;
        for (int k : {0, 1}) {
            for (const auto& [y_prev, cnt_prev] : dp[i][k]) {
                Point p_prev(i, y_prev);
                for (const auto& p_curr : curr_row) {
                    int dx = p_prev.x - p_curr.x;
                    int dy = y_prev - p_curr.y;
                    if (dx * dx + dy * dy > d * d) continue;
                    next_dp[0][p_curr.y] = (next_dp[0][p_curr.y] + cnt_prev) % MOD;
                }
            }
        }
        for (const auto& p1 : curr_row) {
            if (!next_dp[0].count(p1.y)) continue;
            int cnt = next_dp[0][p1.y];
            for (const auto& p2 : curr_row) {
                if (p1.y == p2.y) continue;
                int dx = p1.x - p2.x;
                int dy = p1.y - p2.y;
                if (dx * dx + dy * dy > d * d) continue;
                next_dp[1][p2.y] = (next_dp[1][p2.y] + cnt) % MOD;
            }
        }
        dp[i + 1] = move(next_dp);
    }
    int ans = 0;
    for (int k : {0, 1}) {
        for (const auto& [y, cnt] : dp[n - 1][k]) {
            ans = (ans + cnt) % MOD;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(T!=1) cin>>T;
    while(T--) solve();
    return 0;
}
