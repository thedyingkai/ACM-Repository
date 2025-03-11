#include "iostream"
using namespace std;
char mc[11][11];
char mf[11][11];
int xc,yc,zc=0,xf,yf,zf=0,res=0;
void movec(){
    if(zc==0){
        if(mc[yc-1][xc]!='*'&&yc!=1){yc--;return;}
        else{zc=(zc+1)%4;return;}}
    if(zc==3){
        if(mc[yc][xc-1]!='*'&&xc!=1){xc--;return;}
        else{zc=(zc+1)%4;return;}}
    if(zc==2){
        if(mc[yc+1][xc]!='*'&&yc!=10){yc++;return;}
        else{zc=(zc+1)%4;return;}}
    if(zc==1){
        if(mc[yc][xc+1]!='*'&&xc!=10){xc++;return;}
        else{zc=(zc+1)%4;return;}}
}
void movef(){
    if(zf==0){
        if(mf[yf-1][xf]!='*'&&yf!=1){yf--;return;}
        else{zf=(zf+1)%4;return;}}
    else if(zf==3){
        if(mf[yf][xf-1]!='*'&&xf!=1){xf--;return;}
        else{zf=(zf+1)%4;return;}}
    else if(zf==2){
        if(mf[yf+1][xf]!='*'&&yf!=10){yf++;return;}
        else{zf=(zf+1)%4;return;}}
    else if(zf==1){
        if(mf[yf][xf+1]!='*'&&xf!=10){xf++;return;}
        else{zf=(zf+1)%4;return;}}
}
int main(){
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>mc[i][j];
            mf[i][j]=mc[i][j];
            if(mc[i][j]=='C') yc=i,xc=j,mf[i][j]='.';
            if(mf[i][j]=='F') yf=i,xf=j,mc[i][j]='.';
        }
        getchar();
    }
    while(1){
        res++;
        movec();
        movef();
        if(xc==xf&&yc==yf){
            cout<<res;
            return 0;
        }
        if(res>=10e6){
            cout<<0;
            return 0;
        }
    }
}