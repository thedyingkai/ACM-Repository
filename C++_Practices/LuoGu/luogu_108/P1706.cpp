//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
#include "iomanip"
using namespace std;
int n,x[10];
bool f(int z){
    for(int i=0;i<z-1;i++) if(x[i]==x[z-1]) return 1;
    return 0;
}
void dfs(int i){
    if(f(i)) return;
    if(i>=n){
        for(int j=0;j<n;j++) cout<<setw(5)<<x[j];
        cout<<endl;
        return;
    }
    else for(int j=1;j<=n;j++){
        x[i]=j;
        dfs(i+1);
    }
}
int main(){
    cin>>n;
    x[0]=0;
    dfs(0);
}