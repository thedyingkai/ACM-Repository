//
// Created by ASUS on 2025/2/4.
//
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[110];
double ma=-1;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        double q=0;
        for(int j=0;j<m;j++) cin>>a[j];
        sort(a,a+m);
        for(int i=1;i<m-1;i++) q+=a[i];
        if(q/(m-2)>ma) ma=q/(m-2);
    }
    printf("%.2f",ma);
}