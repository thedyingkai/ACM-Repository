//
// Created by ASUS on 2025/2/4.
//
#include"iostream"
using namespace std;
int a[10086],n;
int ss(int x){
    int i;
    for(i=2;i*i<=x;i++) if(x%i==0) return 1;
    return 0;
}
int main(){
    cin>>n;
    for(int i=4;i<=n;i+=2){
        printf("%d=",i);
        for(int j=2;j<i;j++) if(!ss(j)&&!ss(i-j)){
            printf("%d+%d\n",j,i-j);
            break;
        }
    }
}