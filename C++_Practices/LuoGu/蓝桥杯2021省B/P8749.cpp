#include "iostream"
using namespace std;
typedef long long ll;
ll n;
ll C(ll a,ll b){
    ll res=1;
    for(ll i=a,j=1;j<=b;i--,j++){
        res=res*i/j;
        if(res>n) return res;
    }
    return res;
}
int main(){
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=16;i>=0;i--){
        ll l=2*i,r=10e9,mid,lim;
        while(l<=r){
            mid=(l+r)>>1;
            lim=C(mid,i);
            if(lim==n){
                cout<<(mid+1)*mid/2+i+1;
                return 0;
            }
            else if(lim<n) l=mid+1;
            else r=mid-1;
        }
    }
}