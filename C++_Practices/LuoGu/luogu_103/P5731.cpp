//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
using namespace std;
int a[15][15];
int main(){
    int n,k=1,x=1,y=0;
    cin>>n;
    while(k<=n*n){
        while(y<n&&!a[x][y+1]) a[x][++y]=k++;
        while(x<n&&!a[x+1][y]) a[++x][y]=k++;
        while(y>1&&!a[x][y-1]) a[x][--y]=k++;
        while(x>1&&!a[x-1][y]) a[--x][y]=k++;
    }
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%3d",a[i][j]);
        cout<<endl;
    }
}