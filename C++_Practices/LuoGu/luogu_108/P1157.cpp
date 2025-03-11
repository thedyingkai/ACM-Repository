//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
#include "iomanip"
using namespace std;
int n,r,a[21];
void dfs(int i){
    if(i>r){
        for(int j=1;j<=r;j++) cout<<setw(3)<<a[j];
        cout<<endl;
        return;
    }
    for(int j=a[i-1]+1;j<=n;j++){
        a[i]=j;
        dfs(i+1);
    }
}
int main(){
    cin>>n>>r;
    dfs(1);
}