//
// Created by ASUS on 2025/2/11.
//
#include "iostream"
#include "cstring"
using namespace std;
int t,n,a,x[1001];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++){
            cin>>a;
            x[a]++;
        }
        int s=0;
        for(int i=1;i<=n;i++){
            if(x[i]>2) x[i+1]+=x[i]-2;
            if(x[i]==1) s=1;
        }
        if(s) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}