#include "iostream"
#include "algorithm"
using namespace std;
int n,x;
long long res,a,sum=0,dp;
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
        a=x-a;
        dp=max(a,dp+a);
        res=max(res,dp);
    }
    cout<<sum+max(res,0ll);
}