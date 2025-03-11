//
// Created by ASUS on 2025/2/4.
//
#include "iostream"
using namespace std;
int n,a,b;
char c;
int nu(int x){
    int s=0;
    if(x==0) return 1;
    if(x<0) s++,x=-x;
    while(x>0) x/=10,s++;
    return s;
}
int main(){
    cin>>n;
    while(n--){
        if(!scanf("%d %d",&a,&b)) scanf("%c %d %d",&c,&a,&b);
        if(c=='a') cout<<a<<'+'<<b<<'='<<a+b<<endl<<nu(a)+nu(b)+nu(a+b)+2<<endl;
        else if(c=='b') cout<<a<<'-'<<b<<'='<<a-b<<endl<<nu(a)+nu(b)+nu(a-b)+2<<endl;
        else cout<<a<<'*'<<b<<'='<<a*b<<endl<<nu(a)+nu(b)+nu(a*b)+2<<endl;
    }
}