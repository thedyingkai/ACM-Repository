//
// Created by ASUS on 2025/2/7.
//
#include<iostream>
#include<string>
using namespace std;
int n,a;
string s,sc,sb;
int b,c,d=-1,e;
int main(){
    cin>>n>>s;
    while(n--){
        cin>>a;
        if(a==1){
            cin>>sb;
            s+=sb;
            cout<<s<<endl;
        }
        else if(a==2){
            cin>>b>>c;
            sc=s.substr(b,c);
            s=sc;
            cout<<s;
            cout<<endl;
        }
        else if(a==3){
            cin>>b>>sb;
            s.insert(b,sb);
            cout<<s<<endl;
        }
        else if(a==4){
            cin>>sb;
            if(s.find(sb)<s.size()) cout<<s.find(sb)<<endl;
            else cout<<-1<<endl;
        }
    }
}