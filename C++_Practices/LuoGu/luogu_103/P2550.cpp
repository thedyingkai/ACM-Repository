//
// Created by ASUS on 2025/2/7.
//
#include"iostream"
int n,a,b,d[8];
bool c[34];
using namespace std;
int main(){
    cin>>n;
    for(int i=0;i<7;i++){
        cin>>b;
        c[b]=1;
    }
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<7;j++){
            cin>>a;
            if(c[a]) s++;
        }
        d[7-s]++;
    }
    for(int i=0;i<7;i++) cout<<d[i]<<" ";
}