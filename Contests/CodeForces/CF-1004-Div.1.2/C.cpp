//
// Created by ASUS on 2025/2/11.
//
#include "iostream"
using namespace std;
int t,n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int x=0;x<10;x++){
            int res=7;
            string s=to_string(n-x);
            for(int i=0;i<s.length();i++){
                if(s[i]>='0'&&s[i]<='7') res=min(res,'7'-s[i]);
            }
            if(res<=x){
                cout<<x<<endl;
                break;
            }
        }
    }
}