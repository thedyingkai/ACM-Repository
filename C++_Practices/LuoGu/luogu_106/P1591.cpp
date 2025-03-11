//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
#include "cstring"
using namespace std;
int t,n,aa,ii,sum;
int q[100086];
void mul(int a[],int k){
    for(int i=0;i<ii;i++) a[i]*=k;
    for(int i=0;i<ii;i++){
        if(a[i]>9){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    }
    while(a[ii]){
        a[ii+1]+=a[ii]/10;
        a[ii]%=10;
        ii++;
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>aa;
        memset(q,0,sizeof(q));
        q[0]=1,ii=0,sum=0;
        for(int i=1;i<=n;i++)mul(q,i);
        for(int i=0;i<ii;i++) if(q[i]==aa) sum++;
        cout<<sum<<endl;
    }
}