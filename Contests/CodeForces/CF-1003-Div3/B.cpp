//
// Created by ASUS on 2025/2/9.
//
#include "iostream"
#include "cstring"
using namespace std;
int t;
char s[101];
int main(){
    cin>>t;
    while(t--){
        cin>>s;
        bool x=0;
        for(int i=1;i<strlen(s);i++) if(s[i]==s[i-1]) x=1;
        if(x) cout<<1<<endl;
        else cout<<strlen(s)<<endl;
    }
}