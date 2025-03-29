#include <bits/stdc++.h>
using namespace std;
const int mod=998244853;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n),p(n);
    vector<long long> dp(m,0);
    for(int i=0;i<n;i++) cin>>a[i],a[i]=(a[i]+mod)%mod;
    for(int i=0;i<n;i++) cin>>p[i];
    dp[0]=1;
    int k=1;
    for(int i=0;i<n;i++){
        vector<long long> tem(m,0);
        for(int j=0;j<m;j++){
            tem[j]=(tem[j]+(dp[j]*(1-p[i]+mod)%mod)%mod)%mod;
            tem[(j+a[i])%m]=(tem[(j+a[i])%m]+(dp[j]*p[i])%mod)%mod;
        }
        dp=tem;
    }
    cout<<dp[0]%mod;
}