//
// Created by ASUS on 2025/2/7.
//
#include <cstring>
#include "iostream"
using namespace std;
int m,n,od[405],ma[21][100001],st[21],lt[21],ans=0;
struct st{
    int i;
    int c;
}a[21][21];
int main(){
    cin>>m>>n;
    memset(ma,0,sizeof(ma));
    memset(st,0,sizeof(st));
    memset(lt,0,sizeof(lt));
    for(int i=1;i<=m*n;i++) cin>>od[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j].i;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j].c;
    for(int i=1;i<=m*n;i++){
        int x=od[i];
        st[x]++;
        int id=a[x][st[x]].i,c=a[x][st[x]].c,s=0;
        for(int j=lt[x]+1;;j++){
            if(ma[id][j]==0) s++;
            else s=0;
            if(s==c){
                for(int k=j-c+1;k<=j;k++)  ma[id][k]=1;
                if(j>ans) ans=j;
                lt[x]=j;
                break;
            }
        }
    }
    cout<<ans;
}
