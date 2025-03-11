#include "iostream"
using namespace std;
int n,m,d,v=0,res=0;
char s[5];
pair<string,int> a[100086];
int f(int b,int q){
    for(int i=1;i<=n;i++){
        int x=a[i].second>>b&1;
        if(a[i].first=="AND") q&=x;
        else if(a[i].first=="OR") q|=x;
        else q^=x;
    }
    return q;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s>>d;
        a[i]=make_pair(s,d);
    }
    for(int b=29;b>=0;b--){
        int r0=f(b,0);
        int r1=f(b,1);
        if(v+(1<<b)<=m&&r0<r1){
            v+=1<<b;
            res+=r1<<b;
        }
        else res+=r0<<b;
    }
    cout<<res;
}