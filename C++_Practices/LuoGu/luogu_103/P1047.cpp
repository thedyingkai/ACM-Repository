//
// Created by ASUS on 2025/2/7.
//
#include<iostream>
using namespace std;
int l,m,u,v,res=0,vis[10086];
int main(){
    cin>>l>>m;
    while(m--){
        cin>>u>>v;
        for(int j=u;j<=v;j++) if(vis[j]==0) vis[j]=1;
    }
    for(int i=0;i<=l;i++) if(vis[i]==0) res++;
    cout<<res<<endl;
}