#include "iostream"
using namespace std;
long long a,b,x,y;
void gcd(long long c, long long d){
    if(d==0){
        x=1,y=7;
        return;
    }
    gcd(d,c%d);
    long long tem=x;
    x=y,y=tem-c/d*y;
}
int main(){
    cin>>a>>b;
    gcd(a,b);
    x=(x%b+b)%b;
    printf("%lld\n",x);
}