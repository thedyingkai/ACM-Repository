#include "iostream"
#include "algorithm"
using namespace std;
long long n,m,a[100086],Max=-1;
bool check(long long mid){
    long long res=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>mid){
            sum=a[i];
            res++;
        }
    }
    if(res>m) return 0;
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i],Max=max(Max,a[i]);
    long long l=Max,r=10e9;
    while(l<=r){
        long long mid=(l+r)/2;
        if(!check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<l;
}