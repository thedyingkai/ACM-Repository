//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
#include "cstring"
using namespace std;
int a[10005],m,n;
bool y[10005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i];
        for(int j=1;j<=a[i];j++) x-=y[j];
        y[a[i]]=1;
        a[i]=x-1;
    }
    a[n]+=m;
    for(int i=n;i>0;i--){
        a[i-1]+=a[i]/(n-i+1);
        a[i]%=n-i+1;
    }
    memset(y,0,sizeof(y));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[i];j++) if(y[j]) a[i]++;
        cout<<a[i]+1<<" ";
        y[a[i]]=1;
    }
}