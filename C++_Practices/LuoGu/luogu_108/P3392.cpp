//
// Created by ASUS on 2025/2/13.
//
#include "iostream"
using namespace std;
int n,m,res=10e6,x[52][52];
char c;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        cin>>c;
        if(c=='W') x[i][0]++;
        if(c=='B') x[i][1]++;
        if(c=='R') x[i][2]++;
    }
    for(int j=2;j<=n-1;j++){
        for(int k=j+1;k<=n;k++){
            int sum=0;
            for(int w=1;w<j;w++) sum+=x[w][1]+x[w][2];
            for(int b=j;b<k;b++) sum+=x[b][0]+x[b][2];
            for(int r=k;r<=n;r++) sum+=x[r][1]+x[r][0];
            res=min(res,sum);
        }
    }
    cout<<res;
}