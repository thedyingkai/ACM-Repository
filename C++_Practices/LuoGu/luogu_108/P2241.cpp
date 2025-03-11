//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
using namespace std;
long long n,m,s=0,c=0;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(i==j) s+=(n-i)*(m-j);
        else c+=(n-i)*(m-j);
    }
    cout<<s<<' '<<c;
}