//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    if(a*b==c||a*c==b||b*c==a) cout<<"Yes";
    else cout<<"NO";
}