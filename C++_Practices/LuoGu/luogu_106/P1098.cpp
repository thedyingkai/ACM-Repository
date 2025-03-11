//
// Created by ASUS on 2025/2/7.
//
#include "iostream"
#include "cstring"
using namespace std;
int p1,p2,p3;
char s[105];
int main(){
    cin>>p1>>p2>>p3;
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i+1]-s[i-1]==1) cout<<s[++i];
            else if(s[i+1]<=s[i-1]) cout<<s[i];
            else if((s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i-1]<='9')||(s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<='z'&&s[i-1]>='a')){
                if(p3==1){
                    for(int j=s[i-1]+1;j<s[i+1];j++) for(int k=0;k<p2;k++){
                            if(p1==3) cout<<'*';
                            else if(p1==1||s[i+1]>='0'&&s[i+1]<='9') cout<<char(j);
                            else cout<<char(j+'A'-'a');
                        }
                }
                else if(p3==2){
                    for(int j=s[i+1]-1;j>s[i-1];j--) for(int k=0;k<p2;k++){
                            if(p1==3) cout<<'*';
                            else if(p1==1||s[i+1]>='0'&&s[i+1]<='9') cout<<char(j);
                            else cout<<char(j+'A'-'a');
                        }
                }
            }
            else cout<<s[i];
        }
        else cout<<s[i];
    }
}