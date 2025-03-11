//
// Created by ASUS on 2025/2/7.
//
#include <iostream>
using namespace std;
int w,x,h,res,q;
bool a[21][21][21];
int main(){
    cin>>w>>x>>h>>q;
    while(q--){
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=min(x1,x2)-1;i<max(x1,x2);i++) for(int j=min(y1,y2)-1;j<max(y1,y2);j++) for(int k=min(z1,z2)-1;k<max(z1,z2);k++) a[i][j][k]=1;
    }
    for(int i=0;i<w;i++) for(int j=0;j<x;j++) for(int k=0;k<h;k++) if(!a[i][j][k]) res++;
    cout<<res;
}