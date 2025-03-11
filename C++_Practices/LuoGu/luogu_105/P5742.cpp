//
// Created by ASUS on 2025/2/4.
//
#include <iostream>
using namespace std;
struct st{
    int i,s;
    double a,b,f;
}a[1000];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].i>>a[i].a>>a[i].b;
        a[i].s=a[i].a+a[i].b;
        a[i].f=a[i].a*0.7+a[i].b*0.3;
    }
    for(int i=0;i<n;i++){
        if(a[i].s>140&&a[i].f>=80) cout<<"Excellent"<<endl;
        else cout<<"Not excellent"<<endl;
    }
}