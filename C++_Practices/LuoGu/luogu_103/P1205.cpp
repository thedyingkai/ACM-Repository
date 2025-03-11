#include "iostream"
using namespace std;
int n;
char k;
bool fi[11][11],la[11][11],re[11][11];
bool f1(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(fi[i][j]!=la[j][n+1-i]) return 0;
    return 1;
}
bool f2(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(fi[i][j]!=la[n+1-i][n+1-j]) return 0;
    return 1;
}
bool f3(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(fi[i][j]!=la[n+1-j][i]) return 0;
    return 1;
}
bool f4(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)  if(fi[i][j]!=la[i][n+1-j]) return 0;
    return 1;
}
bool f6(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(fi[i][j]!=la[i][j]) return 0;
    return 1;
}
void str(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) fi[i][j]=re[i][j];
}
void r(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) re[i][j]=fi[i][n+1-j];
    str();
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>k;
            if(k=='@') fi[i][j]=1;
            else if(k=='-') fi[i][j]=0;
            else j--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>k;
            if(k=='@') la[i][j]=1;
            else if(k=='-') la[i][j]=0;
            else j--;
        }
    }
    if(f1()){cout<<1;return 0;}
    if(f2()){cout<<2;return 0;}
    if(f3()){cout<<3;return 0;}
    if(f4()){cout<<4;return 0;}
    r();
    if(f2()||f3()||f1()){cout<<5;return 0;}
    r();
    if(f6()){cout<<6;return 0;}
    cout<<7;
}