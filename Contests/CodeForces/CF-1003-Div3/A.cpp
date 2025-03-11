//
// Created by ASUS on 2025/2/9.
//
#include "iostream"
#include "cstring"
using namespace std;
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        char s[11];
        cin>>s;
        for(int j=0;j<strlen(s)-2;j++) cout<<s[j];
        cout<<'i'<<endl;
    }
}