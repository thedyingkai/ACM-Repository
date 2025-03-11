#include "iostream"
using namespace std;
const long long MOD=1e9+7;
long long qp(long long a, long long b) {
    long long res=1;
    a=a%MOD;
    while(b>0){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res%MOD;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long n,k;
        cin>>n>>k;
        long long ans=(qp(k+1,n+1)-(k+1)%MOD+MOD)%MOD;
        ans*=qp(k,MOD-2);
        ans%=MOD;
        cout<<ans<<endl;
    }
}