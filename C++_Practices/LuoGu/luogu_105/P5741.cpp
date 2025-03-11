//
// Created by ASUS on 2025/2/4.
//
#include "iostream"
struct jgt{std::string a;int x,y,z,b;}a[1005];
int main(){
    int n;std::cin>>n;
    for(int i=0;i<n;i++){std::cin>>a[i].a>>a[i].x>>a[i].y>>a[i].z;a[i].b=a[i].x+a[i].y+a[i].z;}
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if((abs(a[i].x-a[j].x)<=5)&&(abs(a[i].y-a[j].y)<=5)&&(abs(a[i].z-a[j].z)<=5)&&(abs(a[i].b-a[j].b)<=10)) std::cout<<a[i].a<<" "<<a[j].a<<std::endl;
}