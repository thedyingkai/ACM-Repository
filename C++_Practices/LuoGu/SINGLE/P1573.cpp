#include "iostream"
using namespace std;
long long n,ans,j=1;
int main(){
    cin>>n;
    for(long long i=1;i<=n;i++){
        n-=i;
        ans=(ans+i*j)%1000007;
        j=(j*2)%1000007;
    }
    cout<<(ans+n*j)%1000007;
}