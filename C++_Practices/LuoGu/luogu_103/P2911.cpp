//
// Created by ASUS on 2025/2/7.
//
#include<iostream>
#include "algorithm"
using namespace std;
int main(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]<=a[2]-a[1]+1) cout<<1+a[1]+a[0];
    else cout<<2+a[2]+(a[0]-a[2]+a[1]-1)/2;
}
//a=a[2],b=a[0],c=a[1]
//    if(b<=a-c+1)
//        cout<<1+b+c;
//    else
//        cout<<2+a+(b-a+c-1)/2;//int除法自动下取整
//    return 0;
//}