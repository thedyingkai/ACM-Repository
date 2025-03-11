//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
using namespace std;
int n,na,nb,a[205],b[205],sa=0,sb=0;
void j(int x,int y){
    if(x==0){
        if(y==2||y==3) sa++;
        else sb++;
    }
    else if(x==1){
        if(y==0||y==3) sa++;
        else sb++;
    }
    else if(x==2){
        if(y==1||y==4) sa++;
        else sb++;
    }
    else if(x==3){
        if(y==2||y==4) sa++;
        else sb++;
    }
    else if(x==4){
        if(y==0||y==1) sa++;
        else sb++;
    }
}
int main(){
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++) cin>>a[i];
    for(int i=0;i<nb;i++) cin>>b[i];
    int i=0;
    while(n--){
        if(a[i%na]!=b[i%nb]) j(a[i%na],b[i%nb]);
        i++;
    }
    cout<<sa<<' '<<sb;
}