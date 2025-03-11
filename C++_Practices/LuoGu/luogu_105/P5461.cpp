//
// Created by ASUS on 2025/2/4.
//
#include <cstring>
#include "iostream"
using namespace std;
int n;
bool m[1<<10][1<<10];
void d(int x,int y,int u){
    if(u==0) return;
    for(int i=x;i<x+(1<<u)/2;i++) for(int j=y;j<y+(1<<u)/2;j++) m[i][j]=0;
    d(x+(1<<u)/2,y,u-1);
    d(x,y+(1<<u)/2,u-1);
    d(x+(1<<u)/2,y+(1<<u)/2,u-1);
}
int main(){
    cin>>n;
    memset(m,1,sizeof(m));
    d(0,0,n);
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<1<<n;j++){
            if(m[i][j]) cout<<1;
            else cout<<0;
            if(j!=(1<<n)-1)cout<<' ';
        }
        if(i!=(1<<n)-1) cout<<endl;
    }
}