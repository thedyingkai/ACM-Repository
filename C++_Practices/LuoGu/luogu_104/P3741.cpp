//
// Created by ASUS on 2025/2/7.
//
#include<iostream>
using namespace std;
int main(){
    int n,ans=0,x;
    string s;
    cin>>n>>s;
    for(x=0;x<n-1;x++) if(s[x]=='V'&&s[x+1]=='K'){
        ans++;
        s[x]='v';
        s[x+1]='k';
    }
    for(x=0;x<n-1;x++) if(s[x+1]==s[x]){
        ans++;
        cout<<ans;
        return 0;
    }
    cout<<ans;
}