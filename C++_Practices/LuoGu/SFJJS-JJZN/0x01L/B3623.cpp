#include "iostream"
using namespace std;
int n,k,num[21];
bool ch[21],fl;
void f(int x){
    if(x==k+1){
        for(int i=1;i<=k;i++) cout<<num[i]<<' ';
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(ch[i]) continue;
        for(int j=1;j<=x;j++) if(num[j]==i) fl=1;
        if(fl) continue;
        num[x]=i;
        ch[i]=1;
        f(x+1);
        ch[i]=0;
        num[x]=0;
    }
}
int main(){
    cin>>n>>k;
    f(1);
}