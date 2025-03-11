//
// Created by ASUS on 2025/2/4.
//
#include<iostream>
#include<cmath>
using namespace std;
int a[31],n=0;
long long s=0;
int main(){
    while(cin>>a[n++]);
    for(int i=0;i<n;i++) s+=a[i];
    s*=pow(2,n-2);
    cout<<s;
}