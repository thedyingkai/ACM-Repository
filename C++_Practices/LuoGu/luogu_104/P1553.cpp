//
// Created by ASUS on 2025/2/4.
//
#include "iostream"
#include "cstring"
using namespace std;
char s[23],c='\0';
__int128 a[2],f=0;
inline void print(__int128 n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n%10+'0');
}
__int128 re(__int128 x){
    __int128 q=0;
    while(x>0){
        q=q*10+x%10;
        x/=10;
    }
    return q;
}
int main(){
    cin>>s;
    for(__int128 i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9') a[f]=a[f]*10+s[i]-'0';
        else if(f==0){c=s[i],f=1;}
    }
    print(re(a[0]));
    if(c!='\0') cout<<c;
    if(a[1]!=0||c=='.') print(re(a[1]));
}