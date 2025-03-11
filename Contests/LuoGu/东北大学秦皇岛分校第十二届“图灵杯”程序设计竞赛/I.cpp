#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<int> a(m);
        vector<int> b(m);
        long double sum_b=0;
        for(int &x:a) cin>>x;
        for(int &x:b){
            cin>>x;
            sum_b+=x;
        }
        vector<long double> p(m);
        for(int i=0;i<m;++i) p[i]=static_cast<long double>(b[i])/sum_b;
        long double exp_all=0;
        for(int i=0;i<m;++i) exp_all+=p[i]*a[i];
        vector<long double> dp(n+1,0);
        for(int i=1;i<=n;++i){
            long double exp_max=0;
            for(int j=0;j<m;++j) exp_max+=p[j]*max(static_cast<long double>(a[j]),dp[i-1]);
            dp[i]=min(exp_all,exp_max);
        }
        cout<<fixed<<setprecision(6)<<dp[n]<<'\n';
    }
    return 0;
}