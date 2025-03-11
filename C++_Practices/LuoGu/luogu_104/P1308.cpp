//
// Created by ASUS on 2025/2/4.
//
#include <iostream>
#include <string>
using namespace std;
string inputs(){
    string str;
    getline(cin,str);
    int len=str.size();
    for(int i=0;i<len;i++) str[i]=(str[i]>=65&&str[i]<=90)?str[i]+32:str[i];
    return ' '+str+' ';
}
int main(){
    string a,x;
    int i=0,cnt=0,sum;
    x=inputs();
    a=inputs();
    i=a.find(x,i);
    if(i==-1){
        cout<<i;
        return 0;
    }
    else{
        sum=i;
        cnt++;
        i+=x.size()-1;
    }
    while(i<a.size()){
        i=a.find(x,i);
        if(i==-1) break;
        else{
            cnt++;
            i+=x.size()-1;
        }
    }
    cout<<cnt<<' '<<sum;
}