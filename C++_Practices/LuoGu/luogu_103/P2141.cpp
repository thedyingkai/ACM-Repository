//
// Created by ASUS on 2025/2/4.
//
#include "iostream"
using namespace std;
int n,sum=0,s[10001],x[101];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(i!=j&&i!=k&&j!=k&&x[i]==x[j]+x[k]){
                    s[i]=1;
                }
    for(int i=0;i<1001;i++) if(s[i]==1) sum++;
    cout<<sum;
}