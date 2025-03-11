//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
#include "cmath"
using namespace std;
int n,m,x,y,r,z,map[505][505],tem[505][505];
int main(){
    cin>>n>>m;
    for(int i=0;i<n*n;i++) map[i/n][i%n]=i+1;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++) cout<<map[i][j]<<' ';
//        cout<<endl;
//    }
    while(m--){
//        cout<<"---------------"<<endl;
        cin>>y>>x>>r>>z;
        x--,y--;
        for(int i=y-r;i<=y+r;i++) for(int j=x-r;j<=x+r;j++){
            if(!z&1) tem[y-(x-j)][x+(y-i)]=map[i][j];
            else tem[y+(x-j)][x-(y-i)]=map[i][j];
        }
        for(int i=y-r;i<=y+r;i++) for(int j=x-r;j<=x+r;j++) map[i][j]=tem[i][j];
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++) cout<<map[i][j]<<' ';
//            cout<<endl;
//        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j];
            if(j!=n-1) cout<<' ';
        }
        if(i!=n-1) cout<<endl;
    }
}