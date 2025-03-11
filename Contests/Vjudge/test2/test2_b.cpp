#include <iostream>
using namespace std;
double x[100086];
double sum[100086];
int main(){
    int n,k;
    cin >> n >> k;
    double ma=1e5,mi=-1e5;
    for(int i=1;i<=n;++i){
        scanf("%lf",&x[i]);
    }
    while(ma-mi>1e-5){
        double mid=(mi+ma)/2;
        for(int i=1;i<=n;++i) sum[i]=(sum[i-1]+x[i]-mid);
        double ss=-1e6,mm=1e6;
        for(int i=k;i<=n;++i){
            mm=min(mm,sum[i-k]);
            ss=max(ss,sum[i]-mm);
        }
        if(ss>=0) mi=mid;
        else ma=mid;
    }
    cout << (int)(ma*1000) << endl;
    return 0;
}