#include "iostream"
#include <cstring>
using namespace std;
int a,b;
bool isp[100000000];
int p[6000000],cnt=0,n;
void pp(int n){
    memset(isp, 1, sizeof(isp));
    isp[1] = 0;
    for(int i = 2; i <= n; i++){
        if(isp[i]) p[++cnt] = i;
        for(int j = 1; j <= cnt && i*p[j] <= n; j++){
            isp[i*p[j]] = 0;
            if(i % p[j] == 0) break;
        }
    }
}
bool ss(int nn){
    int tepa=nn,tep=0;
    while(tepa>0){
        tep=tep*10+tepa%10;
        tepa/=10;
    }
    return tep==nn;
}
int main(){
    cin>>a>>b;
    pp(b);
    for(int i=1;i<=cnt;i++){
        if(p[i]>=a&&p[i]<=b){
            if(ss(p[i])) printf("%d\n",p[i]);
        }
    }
}