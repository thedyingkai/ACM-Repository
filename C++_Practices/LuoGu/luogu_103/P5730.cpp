//
// Created by ASUS on 2025/2/4.
//
#include "iostream"
using namespace std;
int n;
char x[101];
void xxx(){cout<<"XXX";}
void x_x(){cout<<"X.X";}
void __x(){cout<<"..X";}
void x__(){cout<<"X..";}
int main(){
    cin>>n;getchar();getchar();
    for(int i=0;i<n;i++) x[i]=getchar();
    for(int i=0;i<n;i++){
        if(i!=0) cout<<'.';
        if(x[i]=='0'||x[i]=='2'||x[i]=='3'||x[i]=='5'||x[i]=='6'||x[i]=='7'||x[i]=='8'||x[i]=='9') xxx();
        else if(x[i]=='1') __x();
        else if(x[i]=='4') x_x();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i!=0) cout<<'.';
        if(x[i]=='5'||x[i]=='6') x__();
        else if(x[i]=='1'||x[i]=='2'||x[i]=='3'||x[i]=='7') __x();
        else if(x[i]=='0'||x[i]=='4'||x[i]=='8'||x[i]=='9') x_x();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i!=0) cout<<'.';
        if(x[i]=='2'||x[i]=='3'||x[i]=='4'||x[i]=='5'||x[i]=='6'||x[i]=='8'||x[i]=='9') xxx();
        else if(x[i]=='1'||x[i]=='7') __x();
        else if(x[i]=='0') x_x();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i!=0) cout<<'.';
        if(x[i]=='2') x__();
        else if(x[i]=='1'||x[i]=='3'||x[i]=='4'||x[i]=='5'||x[i]=='7'||x[i]=='9') __x();
        else if(x[i]=='0'||x[i]=='6'||x[i]=='8') x_x();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i!=0) cout<<'.';
        if(x[i]=='0'||x[i]=='2'||x[i]=='3'||x[i]=='5'||x[i]=='6'||x[i]=='8'||x[i]=='9') xxx();
        else if(x[i]=='1'||x[i]=='4'||x[i]=='7') __x();
    }
}