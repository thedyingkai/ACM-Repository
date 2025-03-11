//
// Created by ASUS on 2025/2/4.
//
#include "iostream"
using namespace std;
int x[256],maxn=-1,minn=10e9;
char a[101];
bool test(int n){
    if(n<=1) return 0;
    for(int i=2;i*i<n;i++) if(n%i==0) return 0;
    return 1;
}
int main(){
    cin>>a;
    for(int i=0;a[i]!='\0';i++){
        x[(unsigned int)(a[i])]++;
    }
    for(int i=0;i<256;i++){
        if(x[a[i]]>0&&x[a[i]]<minn) minn=x[a[i]];
        if(x[a[i]]>maxn) maxn=x[a[i]];
    }
    if(test(maxn-minn)) cout<<"Lucky Word"<<endl<<maxn-minn;
    else cout<<"No Answer"<<endl<<'0';
}