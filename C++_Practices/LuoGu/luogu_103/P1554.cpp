//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
int a[10],n,m;
int main(){
    std::cin>>n>>m;
    for(int i=n;i<=m;i++) for(int j=i;j;j/=10) a[j%10]++;
    for(int i=0;i<10;i++) std::cout<<a[i]<<" ";
}