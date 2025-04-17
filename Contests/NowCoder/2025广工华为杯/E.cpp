//
// Created by thedyingkai_ on 2025/3/30.
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
    auto split = [](const string& s, char delimiter) -> vector<string> {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            if (!token.empty()) tokens.push_back(token);
        }
        return tokens;
    };

    string s;
    int x;
    cin >> s >> x;

    auto calculate = [&]() -> tuple<int, int, int, int> {
        int coeff_g = 0, coeff_d = 0, coeff_u = 0, coeff_t = 0;
        auto process_term = [&](const string& term) {
            const int len = term.length();
            for (int i = 0; i < len; ++i) {
                const int weight = (int)pow(10, len - 1 - i);
                switch (term[i]) {
                    case 'G': coeff_g += weight; break;
                    case 'D': coeff_d += weight; break;
                    case 'U': coeff_u += weight; break;
                    case 'T': coeff_t += weight; break;
                }
            }
        };

        vector<string> terms = split(s, '+');
        for (auto& term : terms) process_term(term);

        auto check_valid = [&](int R) -> tuple<bool, int, int> {
            if (coeff_g == 0 && coeff_d == 0)
                return {R == 0, 0, 0};

            for (int g = 0; g < 10; ++g) {
                int remain = R - coeff_g * g;
                if (coeff_d == 0) {
                    if (remain == 0) return {true, g, 0};
                } else if (remain >= 0 && remain % coeff_d == 0) {
                    int d = remain / coeff_d;
                    if (0 <= d && d < 10) return {true, g, d};
                }
            }
            return {false, 0, 0};
        };

        for (int u = 0; u < 10; ++u) {
            for (int t = 0; t < 10; ++t) {
                int remain = x - (coeff_u * u + coeff_t * t);
                if (remain < 0) continue;

                auto [valid, g, d] = check_valid(remain);
                if (valid) return {g, d, u, t};
            }
        }
        return {-1, -1, -1, -1};
    };

    auto [g, d, u, t] = calculate();
    if (g == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << g << " " << d << " " << u << " " << t << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	if(T!=1) cin>>T;
	while(T--) solve();
	return 0;
}
