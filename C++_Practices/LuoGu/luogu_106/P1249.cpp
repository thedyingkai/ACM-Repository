//
// Created by ASUS on 2025/2/7.
//
#include <cstring>
#include "iostream"
using namespace std;
int n,s[1086],t[1000086],c=1,q=1;
void mul(int a[],int k,int ii){
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
        q=ii;
    }
}
int main(){
    cin>>n;
    if(n<5) cout<<n<<endl<<n;
    else{
        for(int i=2;i<=n;i++){
            if(n>=i){
                n-=i;
                s[c++]=i;
            }
            else break;
        }
        for(int i=c-1;i>=1;i--) if(n>0){
            s[i]++;
            n--;
        }
        if(n>0) s[c-1]++;
        memset(t,0,sizeof(t));
        t[0]=1;
        for(int i=1;i<c;i++){
            cout<<s[i]<<" ";
            mul(t,s[i],q);
        }
        cout<<endl;
        for(int i=q-1;i>=0;i--) cout<<t[i];
    }
}