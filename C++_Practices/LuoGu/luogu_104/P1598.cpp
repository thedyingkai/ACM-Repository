//
// Created by ASUS on 2025/2/4.
//
#include <iostream>
#include <algorithm>
using namespace std;
int x[26],i,j,n,maxn=0,t=405;
char a;
int main(){
    while(t--){
        a=getchar();
        if(a>='A'&&a<='Z') x[a-'A']++;
    }
    for(i=0;i<26;i++) maxn=max(maxn,x[i]);
    for(i=maxn;i>0;i--){
        for(j=0;j<26;j++) if(x[j]>=i) cout<<"* ";else cout<<"  ";
        cout<<endl;
    }
    for(i=0;i<26;i++) cout<<(char)(i+'A')<<' ';
}