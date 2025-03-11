#include "iostream"
using namespace std;
long long n,k,s[1000086];
bool f(long long mid){
    long long cnt=0,l=1;
    for(long long i=1;i<=n;++i){
        long long x=s[i]-s[l-1];
        long long t=x*(i-l+1-x);
        if(t>mid){
            ++cnt;
            l=i;
        }
    }
    return cnt+1<=k;
}
int main(){
    cin>>n>>k;
    getchar();
    s[1]=getchar()-'0';
    for(long long i=1;i<=n;i++) s[i+1]=s[i]+getchar()-'0';
    long long l=0,r=s[n]*(n-s[n]),res=r;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(f(mid)){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<res;
}