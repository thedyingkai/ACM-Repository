#include<bits/stdc++.h>
#define mem(p) memset(&p,0,sizeof(p))
using namespace std;
const long long mod=1e8;
long long n,m;
struct mat{long long a[3][3],r,c;};
inline mat mul(mat x,mat y){
    mat p;
    mem(p);
    for(int i=0;i<x.r;i++)
        for(int j=0;j<y.c;j++)
            for(int k=0;k<x.c;k++)
                p.a[i][j]=(p.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
    p.r=x.r,p.c=y.c;
    return p;
}
inline void fast(long long k){
    mat p,ans;
    mem(p),mem(ans);
    p.r=p.c=2;
    p.a[0][0]=p.a[0][1]=p.a[1][0]=1;
    /* p|1 1| ,pr=pc=2
     *  |1 0|
     */
    ans.r=1,ans.c=2;
    ans.a[0][0]=ans.a[0][1]=1;
    /* a|1 1| ,ar=1 ,ac=2
     *  |0 0|
     */
    while(k){
        if(k&1)ans=mul(ans,p);
        p=mul(p,p);
        k>>=1;
    }
    cout<<ans.a[0][0];
}
inline long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int main(){
    scanf("%d%d",&n,&m);
    n=gcd(n,m);
    if(n<=2) printf("1");
    else fast(n-2);
    return 0;
}