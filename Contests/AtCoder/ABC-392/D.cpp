//
// Created by ASUS on 2025/2/8.
//
#include <iomanip>
#include "iostream"
using namespace std;
long long n,k[105],a[105][100005],tem;
double res=0.0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>tem;
            a[i][tem]++;
        }
    }
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
        long long sum=0;
        for(int l=1;l<100005;l++) sum+=a[i][l]*a[j][l];
        res=max(res,sum*1.0/(k[i]*k[j]));
    }
    cout<<fixed<<setprecision(10)<<res;
}