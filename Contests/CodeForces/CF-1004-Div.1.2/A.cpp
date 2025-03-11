//
// Created by ASUS on 2025/2/11.
//
#include "iostream"
using namespace std;
int t,x,y;
int main(){
    cin>>t;
    while(t--){
        cin>>x>>y;
        if((x>y&&(x-y+1)%9==0)||x+1==y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}