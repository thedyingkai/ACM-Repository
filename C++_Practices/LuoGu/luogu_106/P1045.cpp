#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int f[1086],p,res[1086],s[1086];
void r1(){
    memset(s,0,sizeof(s));
    for(int i=1;i<=500;i++) for(int j=1;j<=500;j++) s[i+j-1]+=res[i]*f[j];
    for(int i=1;i<=500;i++){
        s[i+1]+=s[i]/10;
        s[i]%=10;
    }
    memcpy(res,s,sizeof(res));
}
void r2(){
    memset(s,0,sizeof(s));
    for(int i=1;i<=500;i++) for(int j=1;j<=500;j++) s[i+j-1]+=f[i]*f[j];
    for(int i=1;i<=500;i++){
        s[i+1]+=s[i]/10;
        s[i]%=10;
    }
    memcpy(f,s,sizeof(f));
}
int main(){
    scanf("%d",&p);
    printf("%d\n",(int)(log10(2)*p+1));
    res[1]=1,f[1]=2;
    while(p>0){
        if(p&1) r1();
        p/=2;
        r2();
    }
    res[1]--;
    for(int i=500;i>=1;i--){
        if(i!=500&&i%50==0)printf("\n%d",res[i]);
        else printf("%d",res[i]);
    }
}