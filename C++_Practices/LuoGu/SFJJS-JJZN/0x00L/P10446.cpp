#include "iostream"
using namespace std;
long long a,b,p,res=0;
int main(){
    cin>>a>>b>>p;
    for(;b;b>>=1){
        if(b&1) res=(res+a)%p;
        a=(a+a)%p;
    }
    cout<<res%p;
}