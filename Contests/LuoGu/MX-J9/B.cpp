#include "iostream"
using namespace std;
long long a,b;
int main(){
    cin>>a>>b;
    if(a>=b) cout<<a-b;
    else{
        long long c=a;
        long long d=a*2;
        long long n=0;
        for(;b>=d;){c*=2;d*=2;n++;}
        if((b-c)>(d-b)) cout<<d-b+n+1;
        else cout<<b-c+n;
    }
}