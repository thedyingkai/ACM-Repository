//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
using namespace std;
int n,k,x[21],res=0;
bool b[21];
int yee(int x){
    if(x==1) return 1;
    return x*yee(x-1);
}
bool f(int i){
    if(i<2) return 0;
    for(int j=2;j*j<=i;j++) if(i%j==0) return 0;
    return 1;
}
void dfs(int i,int s){
    if(i==k&&f(s)) res++;
    for(int j=0;j<n;j++) if(!b[j]){
        b[j]=1;
        dfs(i+1,s+x[j]);
        b[j]=0;
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>x[i];
    dfs(0,0);
    cout<<res/yee(k);
}