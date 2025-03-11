#include "iostream"
using namespace std;
int n;
long long k,l1,r1,l2,r2,res=0;
void fuck(){
    for(long long y=l1;y<=r1;y++){
        long long x=y;
        for(long long i=0;;i++){
            if(x>r2) break;
            if(x>=l2) res++;
            x*=k;
        }
    }
}
int main(){
    scanf("%d",&n);
    while(n--){
        res=0;
        scanf("%lld %lld %lld %lld %lld",&k,&l1,&r1,&l2,&r2);
        fuck();
        printf("%lld\n",res);
    }
}