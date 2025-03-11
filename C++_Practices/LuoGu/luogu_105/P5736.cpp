//
// Created by ASUS on 2025/2/4.
//
#include<iostream>
int n,a;
using namespace std;
bool f(int x){
    if(x<=1) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
int main(){
    cin>>n;
    while(n--){
        cin>>a;
        if(f(a)) cout<<a<<" ";
    }
}