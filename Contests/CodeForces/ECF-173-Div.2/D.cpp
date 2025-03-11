#include <iostream>
using namespace std;
int T;
long long l,r,G,low,high;
long long gcd(long long a,long long b){
    while(b>0){
        long long temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
void fuck(){
    for(long long t=high-low;t>=0;--t){
        for(long long i=low;i+t<=high;++i){
            if(gcd(i,i+t)==1){
                low=i;
                high=i+t;
                return;
            }
        }
    }
}
int main() {
    cin>>T;
    while(T--){
        cin>>l>>r>>G;
        low=(l+G-1)/G;
        high=r/G;
        if(gcd(high,low)!=1){
            fuck();
        }
        if (low>high||(low==high&&low!=1)) cout<<"-1 -1\n";
        else cout<<low*G<<" "<<high*G<<"\n";
    }
    return 0;
}