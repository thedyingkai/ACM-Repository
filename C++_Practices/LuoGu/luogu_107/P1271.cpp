#include<bits/stdc++.h>
using namespace std;
int a,n,m,b[1086];
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>a,++b[a];
    for(int i=0;i<1000;i++)while(b[i]--)cout<<i<<" ";
    return 0;
}