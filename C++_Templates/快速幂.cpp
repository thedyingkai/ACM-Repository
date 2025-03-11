#include "iostream"
using namespace std;

//快速幂a^b
long long qp(long long a,long long b){
    long long res=1;
    for(;b;b>>=1){
        if(b&1) res*=a;
        a*=a;
    }
    return res;
}

//快速幂a^b%p
long long pp(long long a,long long b,long long p){
    long long res=1;
    while(b>0){
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res%p;
}

//快速乘a*b%p
long long b_mul(long long a, long long b, long long p) {
    unsigned long long c=(unsigned long long)a*b-(unsigned long long)((long double)a/p*b+0.5L)*p;
    return (c+p)%p;
}

//龟速乘a*b%p
long long s_mul(long long a, long long b, long long p){
    int res=0;
    for(;b;b>>=1){
        if(b&1) res=(res+a)%p;
        a=(a+a)%p;
    }
    return res%p;
}

int main(){
    long long a,b,p;
    scanf("%lld %lld %lld",&a,&b,&p);
    cout << pp(a,b,p);
    cout << qp(a,b);
    cout << b_mul(a,b,p);
    cout << s_mul(a,b,p);
    return 0;
}