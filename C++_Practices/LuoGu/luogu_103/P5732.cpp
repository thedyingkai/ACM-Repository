//
// Created by ASUS on 2025/2/7.
//
#include"iostream"
using namespace std;
int a[21][21],n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) a[i][0]=a[i][i]=1;
    for(int i=0;i<n;i++) for(int j=1;j<i;j++) a[i][j]=a[i-1][j]+a[i-1][j-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++) cout<<a[i][j]<<' ';
        cout<<endl;
    }
}