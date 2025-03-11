#include <iostream>
using namespace std;
int x,n,s;
int a[100086];
int sol(){
    int res = n+1;
    int sum=0,l=0,r=0;
    while(1){
        while (sum<s && r<=n){
            sum+=a[r++];
        }
        if(sum<s) break;
        if(sum>=s) res=min(res,r-l);
        sum-=a[l++];
    }
    if(res>n) res=0;
    return res;
}
int main(){
    scanf("%d",&x);
    for(int i=1;i<=x;i++){
        scanf("%d %d",&n,&s);
        for(int j=1;j<=n;j++) {
            scanf("%d",&a[j]);
        }
        printf("%d\n",sol());
        for(int j=1;j<=n;j++) a[j]=0;
    }
    return 0;
}