//
// Created by ASUS on 2025/2/7.
//
#include"iostream"
int main(){int a[3]={0,0,0};char s1,s2;while(scanf("%c:=%c;",&s1,&s2)==2) a[s1-'a']=s2>='0'&&s2<='9'?s2-'0':a[s2-'a'];std::cout<<a[0]<<' '<<a[1]<<' '<<a[2];}