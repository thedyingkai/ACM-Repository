//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
using namespace std;
int n,m,x[1005],a;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        x[a]=1;
    }
    cout<<n-m<<endl;
    for(int i=1;i<=n;i++) if(x[i]==0){
        cout<<i<<' ';
    }
}