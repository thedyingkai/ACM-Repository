//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
using namespace std;
int x,a,t;
bool f=1;
int main(){
    for(cin>>x;x>=0;x--){
        if(f) t=x,f=0;
        cin>>a;
        if(a==0) continue;
        if(x!=t&&a>0) cout<<'+';
        if(x!=0&&a==-1) cout<<'-';
        if(abs(a)>1||x==0) cout<<a;
        if(x>1) cout<<"x^"<<x;
        if(x==1) cout<<'x';
    }
}