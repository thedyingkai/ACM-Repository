//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
#include "cstring"
#include "algorithm"
using namespace std;
int n;
char x[10];
struct st{
    char na[31];
    char zw;     //1-BangZhu，2-FuBangZhu,3-HuFa，4-ZhangLao，5-TangZhu，6-JingYing，7-BangZhong
    long bg;
    int lv;
    int i;
}p[111];
bool cmp1(st x,st y){
    if(x.bg!=y.bg) return x.bg>y.bg;
    else return x.i<y.i;
}
bool cmp2(st x,st y){
    if(x.zw!=y.zw) return x.zw<y.zw;
    else if(x.lv!=y.lv) return x.lv>y.lv;
    else return x.i<y.i;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].na>>x>>p[i].bg>>p[i].lv;
        p[i].i=i;
        if(!strcmp(x,"BangZhu")) p[i].zw=1;
        if(!strcmp(x,"FuBangZhu")) p[i].zw=2;
        if(!strcmp(x,"HuFa")) p[i].zw=3;
        if(!strcmp(x,"ZhangLao")) p[i].zw=4;
        if(!strcmp(x,"TangZhu")) p[i].zw=5;
        if(!strcmp(x,"JingYing")) p[i].zw=6;
        if(!strcmp(x,"BangZhong")) p[i].zw=7;
    }
    sort(p+3,p+n,cmp1);
    for(int i=0;i<n;i++){
        if(i==0) p[i].zw=1;
        else if(i<=2) p[i].zw=2;
        else if(i<=4) p[i].zw=3;
        else if(i<=8) p[i].zw=4;
        else if(i<=15) p[i].zw=5;
        else if(i<=40) p[i].zw=6;
        else p[i].zw=7;
    }
    sort(p+3,p+n,cmp2);
    for(int i=0;i<n;i++){
        cout<<p[i].na<<' ';
        if(i==0) cout<<"BangZhu ";
        else if(i<=2) cout<<"FuBangZhu ";
        else if(i<=4) cout<<"HuFa ";
        else if(i<=8) cout<<"ZhangLao ";
        else if(i<=15) cout<<"TangZhu ";
        else if(i<=40) cout<<"JingYing ";
        else cout<<"BangZhong ";
        cout<<p[i].lv<<endl;
    }
}