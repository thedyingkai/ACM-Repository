//
// Created by ASUS on 2025/2/6.
//
#include "iostream"
using namespace std;
int n,m,b,cnt=0;
bool t;
struct st{
    char na[11];
    bool to;
}pe[100086];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>pe[i].to>>pe[i].na;
    while(m--){
        cin>>t>>b;
        //int q=0;
        //if(cnt-b<0) q=1;
        if(t xor pe[cnt].to) cnt=(cnt+b)%n;
        else cnt=(cnt+n-b)%n;
        //cout<<pe[cnt].na<<endl;
    }
    cout<<pe[cnt].na;
}