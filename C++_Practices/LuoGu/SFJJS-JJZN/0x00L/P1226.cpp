#include "iostream"
using namespace std;
long long a,b,p,res=1;
long long f(){
    for(;b;b>>=1){
        if(b&1) res=res*a%p;
        a=a*a%p;
    }
    return res%p;
}
int main(){
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<'='<<f();
}