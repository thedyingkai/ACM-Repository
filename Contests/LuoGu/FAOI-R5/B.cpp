#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll T,n,m,jc[2000006],inv[2000005];
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
ll c(ll a,ll b){return jc[a]*inv[a-b]%mod*inv[b]%mod;}
int main(){
    cin>>T;
    jc[0]=1;
    for(ll i = 1;i<=2000000;i++) jc[i]=jc[i-1]*i%mod;
    inv[2000000]=qpow(jc[2000000],mod-2);
    for(ll i=1999999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
    while(T--){
        cin>>n>>m;
        if(!n&&!m){
            cout<<"1"<<endl;
            continue;
        }
        cout<<(c(n+m,n)+(n+m-1)*c(n+m-2,n-1)%mod*2%mod)%mod<<'\n';
    }
    return 0;
}