//
// Created by ASUS on 2025/2/7.
//
#include"iostream"
using namespace std;
int n,m,a[100001],mi=10e6,t=0;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<=n-m;i++,t=0){
        for(int j=0;j<m;j++) t+=a[i+j];
        if(t<mi) mi=t;
    }
    cout<<mi;
}