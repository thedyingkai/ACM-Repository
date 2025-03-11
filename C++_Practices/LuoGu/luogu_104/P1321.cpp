//
// Created by ASUS on 2025/2/7.
//
#include"iostream"
using namespace std;
int main(){
    int a=0,b=0;
    string s;
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]=='b'||s[i+1]=='o'||s[i+2]=='y') a++;
        if(s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l') b++;
    }
    cout<<a<<endl<<b<<endl;
}