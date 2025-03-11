//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
using namespace std;
int n,m[10086][11],x[11];
long long cnt=0;
void dfs(int i,int s){
    if(i==10&&s==n){
        for(int j=0;j<10;j++) m[cnt][j]=x[j];
        cnt++;
        return;
    }
    else if(i==10||s>=n) return;
    else for(int j=1;j<=3;j++){
        x[i]=j;
        dfs(i+1,s+j);
    }
}
int main(){
    cin>>n;
    if(n<10||n>30){cout<<0;return 0;}
    dfs(0,0);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        for(int j=0;j<10;j++) cout<<m[i][j]<<' ';
        cout<<endl;
    }
}