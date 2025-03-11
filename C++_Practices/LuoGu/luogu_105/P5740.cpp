//
// Created by ASUS on 2025/2/4.
//
#include<iostream>
using namespace std;
string a[1005];
int b[1005],c[1005],d[1005],n,m=-1,t;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i=0;i<n;i++) if(b[i]+c[i]+d[i]>m){
        m=b[i]+c[i]+d[i];
        t=i;
    }
    cout<<a[t]<<" "<<b[t]<<" "<<c[t]<<" "<<d[t];
}