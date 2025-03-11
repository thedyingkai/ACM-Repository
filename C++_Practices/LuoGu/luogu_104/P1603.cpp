//
// Created by ASUS on 2025/2/4.
//
#include "iostream"
#include<bits/stdc++.h>
using namespace std;
char dic[27][10]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
int di[27]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
unsigned long long int a[10],top,flag;
int i,j;
char s[100];
int main(){
    for(i=1;i<=6;i++){
        cin>>s;
        for(j=1;j<=26;j++) if(!strcmp(s,dic[j])){
            a[++top]=di[j];
            break;
        }
    }
    sort(a+1,a+top+1);
    for(i=1;i<=top;i++){
        if(flag) printf("%.2d",a[i]);
        else if(a[i]){
            printf("%d",a[i]);
            flag=1;
        }
    }
    if(!flag) cout<<0;
}